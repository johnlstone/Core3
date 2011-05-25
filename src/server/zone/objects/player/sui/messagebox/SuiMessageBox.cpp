/*
 *	server/zone/objects/player/sui/messagebox/SuiMessageBox.cpp generated by engine3 IDL compiler 0.60
 */

#include "SuiMessageBox.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/player/PlayerCreature.h"


// Imported class dependencies

#include "system/util/Vector.h"

#include "system/io/ObjectOutputStream.h"

#include "server/zone/objects/player/badges/Badges.h"

#include "server/zone/managers/professions/ProfessionManager.h"

#include "server/zone/objects/player/events/PlayerDisconnectEvent.h"

#include "server/zone/objects/area/ActiveArea.h"

#include "server/zone/objects/scene/variables/StringId.h"

#include "engine/core/Task.h"

#include "engine/core/ManagedObject.h"

#include "engine/service/proto/BasePacket.h"

#include "server/zone/objects/player/events/PlayerRecoveryEvent.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/objects/tangible/tool/CraftingTool.h"

#include "server/chat/room/ChatRoom.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "server/zone/managers/objectcontroller/ObjectController.h"

#include "server/zone/managers/city/CityManager.h"

#include "server/zone/managers/creature/CreatureManager.h"

#include "server/login/account/Account.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "system/util/SortedVector.h"

#include "server/zone/objects/player/ValidatedPosition.h"

#include "system/lang/Time.h"

#include "server/zone/objects/cell/CellObject.h"

#include "server/zone/managers/object/ObjectMap.h"

#include "engine/util/Facade.h"

#include "server/zone/objects/player/TradeContainer.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "system/util/VectorMap.h"

#include "server/login/account/AccountManager.h"

#include "server/zone/managers/vendor/VendorManager.h"

#include "server/zone/objects/tangible/tool/SurveyTool.h"

#include "server/zone/ZonePacketHandler.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/managers/planet/MapLocationTable.h"

#include "engine/util/u3d/Quaternion.h"

#include "engine/util/u3d/Coordinate.h"

#include "server/zone/objects/building/BuildingObject.h"

#include "engine/stm/TransactionalReference.h"

#include "server/zone/objects/tangible/sign/SignObject.h"

#include "server/zone/ZoneProcessServer.h"

#include "server/zone/Zone.h"

#include "server/zone/managers/sui/SuiManager.h"

#include "server/zone/objects/player/sui/SuiCallback.h"

#include "server/zone/managers/name/NameManager.h"

#include "server/zone/managers/holocron/HolocronManager.h"

#include "engine/service/proto/BaseClientProxy.h"

#include "server/zone/objects/scene/variables/PendingTasksMap.h"

#include "engine/util/u3d/QuadTreeEntry.h"

#include "engine/util/u3d/QuadTree.h"

#include "server/zone/packets/ui/SuiCreatePageMessage.h"

#include "server/zone/ZoneClientSession.h"

#include "system/io/ObjectInputStream.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "server/zone/managers/planet/HeightMap.h"

#include "engine/core/ObjectUpdateToDatabaseTask.h"

#include "server/zone/objects/player/sui/SuiBox.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/managers/planet/PlanetManager.h"

/*
 *	SuiMessageBoxStub
 */

enum {RPC_GENERATEMESSAGE__ = 6,RPC_ISMESSAGEBOX__};

SuiMessageBox::SuiMessageBox(PlayerCreature* player, unsigned int windowType) : SuiBox(DummyConstructorParameter::instance()) {
	SuiMessageBoxImplementation* _implementation = new SuiMessageBoxImplementation(player, windowType);
	ManagedObject::_setImplementation(_implementation);
	_implementation->_setStub(this);
}

SuiMessageBox::SuiMessageBox(DummyConstructorParameter* param) : SuiBox(param) {
}

SuiMessageBox::~SuiMessageBox() {
}


BaseMessage* SuiMessageBox::generateMessage() {
	SuiMessageBoxImplementation* _implementation = (SuiMessageBoxImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GENERATEMESSAGE__);

		return (BaseMessage*) method.executeWithObjectReturn();
	} else
		return _implementation->generateMessage();
}

bool SuiMessageBox::isMessageBox() {
	SuiMessageBoxImplementation* _implementation = (SuiMessageBoxImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISMESSAGEBOX__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isMessageBox();
}

DistributedObjectServant* SuiMessageBox::_getImplementation() {

	_updated = true;
	return dynamic_cast<DistributedObjectServant*>(getForUpdate());}

void SuiMessageBox::_setImplementation(DistributedObjectServant* servant) {
	setObject(dynamic_cast<SuiMessageBoxImplementation*>(servant));
}

/*
 *	SuiMessageBoxImplementation
 */

SuiMessageBoxImplementation::SuiMessageBoxImplementation(DummyConstructorParameter* param) : SuiBoxImplementation(param) {
	_initializeImplementation();
}


SuiMessageBoxImplementation::~SuiMessageBoxImplementation() {
}


void SuiMessageBoxImplementation::finalize() {
}

void SuiMessageBoxImplementation::_initializeImplementation() {
	_setClassHelper(SuiMessageBoxHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void SuiMessageBoxImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (SuiMessageBox*) stub;
	SuiBoxImplementation::_setStub(stub);
}

DistributedObjectStub* SuiMessageBoxImplementation::_getStub() {
	return _this;
}

SuiMessageBoxImplementation::operator const SuiMessageBox*() {
	return _this;
}

Object* SuiMessageBoxImplementation::clone() {
	return dynamic_cast<Object*>(new SuiMessageBoxImplementation(*this));
}


void SuiMessageBoxImplementation::lock(bool doLock) {
}

void SuiMessageBoxImplementation::lock(ManagedObject* obj) {
}

void SuiMessageBoxImplementation::rlock(bool doLock) {
}

void SuiMessageBoxImplementation::wlock(bool doLock) {
}

void SuiMessageBoxImplementation::wlock(ManagedObject* obj) {
}

void SuiMessageBoxImplementation::unlock(bool doLock) {
}

void SuiMessageBoxImplementation::runlock(bool doLock) {
}

void SuiMessageBoxImplementation::_serializationHelperMethod() {
	SuiBoxImplementation::_serializationHelperMethod();

	_setClassName("SuiMessageBox");

}

void SuiMessageBoxImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(SuiMessageBoxImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool SuiMessageBoxImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (SuiBoxImplementation::readObjectMember(stream, _name))
		return true;


	return false;
}

void SuiMessageBoxImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = SuiMessageBoxImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int SuiMessageBoxImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;

	return 0 + SuiBoxImplementation::writeObjectMembers(stream);
}

SuiMessageBoxImplementation::SuiMessageBoxImplementation(PlayerCreature* player, unsigned int windowType) : SuiBoxImplementation(player, windowType, SuiBox::MESSAGEBOX) {
	_initializeImplementation();
	// server/zone/objects/player/sui/messagebox/SuiMessageBox.idl():  		;
}

bool SuiMessageBoxImplementation::isMessageBox() {
	// server/zone/objects/player/sui/messagebox/SuiMessageBox.idl():  		return true;
	return true;
}

/*
 *	SuiMessageBoxAdapter
 */

SuiMessageBoxAdapter::SuiMessageBoxAdapter(SuiMessageBoxImplementation* obj) : SuiBoxAdapter(obj) {
}

Packet* SuiMessageBoxAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_GENERATEMESSAGE__:
		resp->insertLong(generateMessage()->_getObjectID());
		break;
	case RPC_ISMESSAGEBOX__:
		resp->insertBoolean(isMessageBox());
		break;
	default:
		return NULL;
	}

	return resp;
}

BaseMessage* SuiMessageBoxAdapter::generateMessage() {
	return ((SuiMessageBoxImplementation*) impl)->generateMessage();
}

bool SuiMessageBoxAdapter::isMessageBox() {
	return ((SuiMessageBoxImplementation*) impl)->isMessageBox();
}

/*
 *	SuiMessageBoxHelper
 */

SuiMessageBoxHelper* SuiMessageBoxHelper::staticInitializer = SuiMessageBoxHelper::instance();

SuiMessageBoxHelper::SuiMessageBoxHelper() {
	className = "SuiMessageBox";

	Core::getObjectBroker()->registerClass(className, this);
}

void SuiMessageBoxHelper::finalizeHelper() {
	SuiMessageBoxHelper::finalize();
}

DistributedObject* SuiMessageBoxHelper::instantiateObject() {
	return new SuiMessageBox(DummyConstructorParameter::instance());
}

DistributedObjectServant* SuiMessageBoxHelper::instantiateServant() {
	return new SuiMessageBoxImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* SuiMessageBoxHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new SuiMessageBoxAdapter((SuiMessageBoxImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

