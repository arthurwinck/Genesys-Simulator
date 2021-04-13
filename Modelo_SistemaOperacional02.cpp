/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Modelo_SistemasOperacionais02.cpp
 * Author: rlcancian
 * 
 * Created on 12 de abril de 2021, 21:54
 */

#include "Modelo_SistemaOperacional02.h"

#include "Simulator.h"
#include "Model.h"
#include "Create.h"
#include "Assign.h"
#include "Seize.h"
#include "Route.h"
#include "Enter.h"
#include "Decide.h"
#include "Delay.h"
#include "Release.h"
#include "Dispose.h"

#include "EntityType.h"
#include "SeizableItemRequest.h"
#include "Station.h"
#include "Attribute.h"

Modelo_SistemaOperacional02::Modelo_SistemaOperacional02() {
}

int Modelo_SistemaOperacional02::main(int argc, char** argv) {
	Simulator* genesys = new Simulator();
	this->setDefaultTraceHandlers(genesys->getTracer());
	this->insertFakePluginsByHand(genesys);
	genesys->getTracer()->setTraceLevel(Util::TraceLevel::everythingMostDetailed);

	Model* m = genesys->getModels()->newModel();
	m->load("./models/SistemaOperacional02.txt");
	m->getSimulation()->start();
	return;
	EntityType* et = new EntityType(m, "processo");
	Create* c1 = new Create(m, "Processo é criado no computador");
	c1->setEntityType(et);
	c1->setTimeBetweenCreationsExpression("expo(10)");
	c1->setTimeUnit(Util::TimeUnit::milisecond);
	Assign* a1 = new Assign(m, "Define tempo de execução e memória ocupada");
	a1->getAssignments()->insert(new Assign::Assignment("memoriaOcupada", "TRUNC(UNIF(10,50))"));
	a1->getAssignments()->insert(new Assign::Assignment("tempoExecucao", "NORM(3,1) * memoriaOcupada/10"));
	Attribute* att1 = new Attribute(m, "memoriaOcupada");
	Attribute* att2 = new Attribute(m, "tempoExecucao");
	c1->getNextComponents()->insert(a1);
	Resource* mem = new Resource(m, "memoria");
	mem->setCapacity(64);
	Queue* q1 = new Queue(m, "Fila_Alocacao_Memoria");
	Seize* sz1 = new Seize(m, "Processo aloca memória");
	a1->getNextComponents()->insert(sz1);
	sz1->setQueue(q1);
	sz1->getSeizeRequests()->insert(new SeizableItemRequest(mem, "memoriaOcupada"));
	Station* st1 = new Station(m, "Estacao de Execucao");
	Route* r1 = new Route(m, "Processo é enviado para execução na CPU");
	r1->setStation(st1);
	sz1->getNextComponents()->insert(r1);

	Enter* e1 = new Enter(m, "Processo chega para ser executado");
	e1->setStation(st1);
	Resource* cpu = new Resource(m, "CPU");
	Queue* q2 = new Queue(m, "Fila_CPU");
	Seize* sz2 = new Seize(m, "Processo aloca CPU");
	sz2->setQueue(q2);
	sz2->getSeizeRequests()->insert(new SeizableItemRequest(cpu, "1"));
	e1->getNextComponents()->insert(sz2);
	Decide* dec1 = new Decide(m, "Define tempo de execução da fatia de tempo atual");
	dec1->getConditions()->insert("tempoExecucao >= 1");
	sz2->getNextComponents()->insert(dec1);
	Assign* a2 = new Assign(m, "Define execucao por um quantum de tempo");
	a2->getAssignments()->insert(new Assign::Assignment("fatiaTempo", "1"));
	a2->getAssignments()->insert(new Assign::Assignment("tempoExecucao", "tempoExecucao-fatiaTempo"));
	Attribute* att3 = new Attribute(m, "fatiaTempo");
	dec1->getNextComponents()->insert(a2);
	Assign* a3 = new Assign(m, "Executa até o final");
	a3->getAssignments()->insert(new Assign::Assignment("fatiaTempo", "tempoExecucao"));
	a3->getAssignments()->insert(new Assign::Assignment("tempoExecucao", "tempoExecucao-fatiaTempo"));
	dec1->getNextComponents()->insert(a3);
	Delay* dl1 = new Delay(m, "Processo executa na CPU");
	dl1->setDelayExpression("fatiaTempo");
	dl1->setDelayTimeUnit(Util::TimeUnit::milisecond);
	a2->getNextComponents()->insert(dl1);
	a3->getNextComponents()->insert(dl1);
	Release* rl1 = new Release(m, "Processo libera CPU");
	rl1->getReleaseRequests()->insert(new SeizableItemRequest(cpu, "1"));
	dl1->getNextComponents()->insert(rl1);
	Decide* dc2 = new Decide(m, "Se processo ainda precisa executar então vai para estação de execução");
	dc2->getConditions()->insert("tempoExecucao > 0");
	rl1->getNextComponents()->insert(dc2);
	Route* r2 = new Route(m, "Processo é enviado de volta para execução");
	r2->setStation(st1);
	dc2->getNextComponents()->insert(r2);
	Station* st2 = new Station(m, "Estacao de liberação de memória");
	Route* r3 = new Route(m, "Processo é enviado para liberar memória");
	r3->setStation(st2);
	dc2->getNextComponents()->insert(r3);

	Enter* e2 = new Enter(m, "Processo chega para liberar memória");
	e2->setStation(st2);
	Release* rl2 = new Release(m, "Processo libera memória");
	rl2->getReleaseRequests()->insert(new SeizableItemRequest(mem, "memoriaOcupada"));
	e2->getNextComponents()->insert(rl2);
	Dispose* disp1 = new Dispose(m, "Processo é encerrado");
	rl2->getNextComponents()->insert(disp1);

	ModelSimulation* sim = m->getSimulation();
	sim->setReplicationLength(1);
	sim->setReplicationLengthTimeUnit(Util::TimeUnit::second);
	genesys->getTracer()->setTraceLevel(Util::TraceLevel::everythingMostDetailed);
	m->save("./models/SistemaOperacional02.txt");
	sim->start();
}