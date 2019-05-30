/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModelElement.cpp
 * Author: rafael.luiz.cancian
 * 
 * Created on 21 de Junho de 2018, 19:40
 */

//#include <typeinfo>
#include <iostream>   
#include "ModelElement.h"

ModelElement::ModelElement(std::string thistypename) {
    _id = Util::GenerateNewIdOfType(thistypename);
    _name = thistypename + " " + std::to_string(_id);
    _typename = thistypename;
}

ModelElement::ModelElement(const ModelElement& orig) {
}

ModelElement::~ModelElement() {
}

void ModelElement::_loadInstance(std::map<std::string, std::string>* fields) {
    this->_id = std::stoi((*fields->find("id")).second);
    this->_name = (*fields->find("name")).second;
}

std::map<std::string, std::string>* ModelElement::_saveInstance() {
    std::map<std::string, std::string>* fields = new std::map<std::string,std::string>();
    fields->emplace("typename", this->_typename);
    fields->emplace("id" , std::to_string(this->_id));
    fields->emplace("name" , this->_name);
    return fields;
}

/*
std::list<std::map<std::string,std::string>*>* ModelElement::_saveInstance(std::string type) {
    std::list<std::map<std::string,std::string>*>* fields = ModelElement::_saveInstance();
    fields->push_back(type);
    return fields;
}
 */

std::string ModelElement::show() {
    return "id=" + std::to_string(_id) + ",name=\"" + _name + "\"";
}

Util::identitifcation ModelElement::getId() const {
    return _id;
}

void ModelElement::setName(std::string _name) {
    this->_name = _name;
}

std::string ModelElement::getName() const {
    return _name;
}

std::string ModelElement::getTypename() const {
    return _typename;
}

//std::list<std::map<std::string,std::string>*>* ModelElement::_saveInstance() { /* TODO: REMOVE - IS PURE VIRTUAL  TEMP */
//	std::list<std::map<std::string,std::string>*>* fiels = new std::map<std::string,std::string>();
//	return fields;
//}

ModelElement* ModelElement::LoadInstance(std::map<std::string, std::string>* fields) {
    
}

std::map<std::string, std::string>* ModelElement::SaveInstance(ModelElement* element) {
    std::map<std::string, std::string>* fields; // = new std::list<std::string>();
    try {
	fields = element->_saveInstance();
    } catch (const std::exception& e) {
	//element->_model->getTrace()->traceError(e, "Error saving infra " + element->show());
    }
    return fields;
}

bool ModelElement::Check(ModelElement* element, std::string* errorMessage) {
    //    element->_model->getTracer()->trace(Util::TraceLevel::mostDetailed, "Checking " + element->_typename + ": " + element->_name); //std::to_string(element->_id));
    bool res = false;
    Util::IncIndent();
    {
	try {
	    res = element->_check(errorMessage);
	    if (!res) {
		//                element->_model->getTracer()->trace(Util::TraceLevel::errors, "Error: Checking has failed with message '" + *errorMessage + "'");
	    }
	} catch (const std::exception& e) {
	    //            element->_model->getTracer()->traceError(e, "Error verifying element " + element->show());
	}
    }
    Util::DecIndent();
    return res;
}