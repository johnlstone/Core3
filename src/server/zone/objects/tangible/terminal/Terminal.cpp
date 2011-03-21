/*
 *	server/zone/objects/tangible/terminal/Terminal.cpp generated by engine3 IDL compiler 0.60
 */

#include "Terminal.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/Zone.h"

/*
 *	TerminalStub
 */

enum {RPC_INITIALIZETRANSIENTMEMBERS__ = 6,RPC_ISTERMINAL__,RPC_ISGUILDTERMINAL__,RPC_SETCONTROLLEDOBJECT__SCENEOBJECT_,RPC_GETCONTROLLEDOBJECT__,RPC_ISELEVATORTERMINAL__};

Terminal::Terminal() : TangibleObject(DummyConstructorParameter::instance()) {
	TerminalImplementation* _implementation = new TerminalImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
}

Terminal::Terminal(DummyConstructorParameter* param) : TangibleObject(param) {
}

Terminal::~Terminal() {
}


void Terminal::initializeTransientMembers() {
	TerminalImplementation* _implementation = (TerminalImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZETRANSIENTMEMBERS__);

		method.executeWithVoidReturn();
	} else
		_implementation->initializeTransientMembers();
}

bool Terminal::isTerminal() {
	TerminalImplementation* _implementation = (TerminalImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISTERMINAL__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isTerminal();
}

bool Terminal::isGuildTerminal() {
	TerminalImplementation* _implementation = (TerminalImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISGUILDTERMINAL__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isGuildTerminal();
}

void Terminal::setControlledObject(SceneObject* obj) {
	TerminalImplementation* _implementation = (TerminalImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETCONTROLLEDOBJECT__SCENEOBJECT_);
		method.addObjectParameter(obj);

		method.executeWithVoidReturn();
	} else
		_implementation->setControlledObject(obj);
}

SceneObject* Terminal::getControlledObject() {
	TerminalImplementation* _implementation = (TerminalImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETCONTROLLEDOBJECT__);

		return (SceneObject*) method.executeWithObjectReturn();
	} else
		return _implementation->getControlledObject();
}

bool Terminal::isElevatorTerminal() {
	TerminalImplementation* _implementation = (TerminalImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISELEVATORTERMINAL__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isElevatorTerminal();
}

DistributedObjectServant* Terminal::_getImplementation() {

	_updated = true;
	return _impl;
}

void Terminal::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	TerminalImplementation
 */

TerminalImplementation::TerminalImplementation(DummyConstructorParameter* param) : TangibleObjectImplementation(param) {
	_initializeImplementation();
}


TerminalImplementation::~TerminalImplementation() {
}


void TerminalImplementation::finalize() {
}

void TerminalImplementation::_initializeImplementation() {
	_setClassHelper(TerminalHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void TerminalImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (Terminal*) stub;
	TangibleObjectImplementation::_setStub(stub);
}

DistributedObjectStub* TerminalImplementation::_getStub() {
	return _this;
}

TerminalImplementation::operator const Terminal*() {
	return _this;
}

void TerminalImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void TerminalImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void TerminalImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void TerminalImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void TerminalImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void TerminalImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void TerminalImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void TerminalImplementation::_serializationHelperMethod() {
	TangibleObjectImplementation::_serializationHelperMethod();

	_setClassName("Terminal");

}

void TerminalImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(TerminalImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool TerminalImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (TangibleObjectImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "controlledObject") {
		TypeInfo<ManagedReference<SceneObject* > >::parseFromBinaryStream(&controlledObject, stream);
		return true;
	}


	return false;
}

void TerminalImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = TerminalImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int TerminalImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "controlledObject";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<ManagedReference<SceneObject* > >::toBinaryStream(&controlledObject, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 1 + TangibleObjectImplementation::writeObjectMembers(stream);
}

TerminalImplementation::TerminalImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/terminal/Terminal.idl():  		Logger.setLoggingName("Terminal");
	Logger::setLoggingName("Terminal");
	// server/zone/objects/tangible/terminal/Terminal.idl():  		controlledObject = null;
	controlledObject = NULL;
}

bool TerminalImplementation::isTerminal() {
	// server/zone/objects/tangible/terminal/Terminal.idl():  		return true;
	return true;
}

bool TerminalImplementation::isGuildTerminal() {
	// server/zone/objects/tangible/terminal/Terminal.idl():  		return false;
	return false;
}

void TerminalImplementation::setControlledObject(SceneObject* obj) {
	// server/zone/objects/tangible/terminal/Terminal.idl():  		controlledObject = obj;
	controlledObject = obj;
}

SceneObject* TerminalImplementation::getControlledObject() {
	// server/zone/objects/tangible/terminal/Terminal.idl():  		return controlledObject;
	return controlledObject;
}

bool TerminalImplementation::isElevatorTerminal() {
	// server/zone/objects/tangible/terminal/Terminal.idl():  		return false;
	return false;
}

/*
 *	TerminalAdapter
 */

TerminalAdapter::TerminalAdapter(TerminalImplementation* obj) : TangibleObjectAdapter(obj) {
}

Packet* TerminalAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_INITIALIZETRANSIENTMEMBERS__:
		initializeTransientMembers();
		break;
	case RPC_ISTERMINAL__:
		resp->insertBoolean(isTerminal());
		break;
	case RPC_ISGUILDTERMINAL__:
		resp->insertBoolean(isGuildTerminal());
		break;
	case RPC_SETCONTROLLEDOBJECT__SCENEOBJECT_:
		setControlledObject((SceneObject*) inv->getObjectParameter());
		break;
	case RPC_GETCONTROLLEDOBJECT__:
		resp->insertLong(getControlledObject()->_getObjectID());
		break;
	case RPC_ISELEVATORTERMINAL__:
		resp->insertBoolean(isElevatorTerminal());
		break;
	default:
		return NULL;
	}

	return resp;
}

void TerminalAdapter::initializeTransientMembers() {
	((TerminalImplementation*) impl)->initializeTransientMembers();
}

bool TerminalAdapter::isTerminal() {
	return ((TerminalImplementation*) impl)->isTerminal();
}

bool TerminalAdapter::isGuildTerminal() {
	return ((TerminalImplementation*) impl)->isGuildTerminal();
}

void TerminalAdapter::setControlledObject(SceneObject* obj) {
	((TerminalImplementation*) impl)->setControlledObject(obj);
}

SceneObject* TerminalAdapter::getControlledObject() {
	return ((TerminalImplementation*) impl)->getControlledObject();
}

bool TerminalAdapter::isElevatorTerminal() {
	return ((TerminalImplementation*) impl)->isElevatorTerminal();
}

/*
 *	TerminalHelper
 */

TerminalHelper* TerminalHelper::staticInitializer = TerminalHelper::instance();

TerminalHelper::TerminalHelper() {
	className = "Terminal";

	Core::getObjectBroker()->registerClass(className, this);
}

void TerminalHelper::finalizeHelper() {
	TerminalHelper::finalize();
}

DistributedObject* TerminalHelper::instantiateObject() {
	return new Terminal(DummyConstructorParameter::instance());
}

DistributedObjectServant* TerminalHelper::instantiateServant() {
	return new TerminalImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* TerminalHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new TerminalAdapter((TerminalImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

