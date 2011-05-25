/*
 *	server/zone/managers/loot/lootgroup/LootGroupObject.cpp generated by engine3 IDL compiler 0.60
 */

#include "LootGroupObject.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/managers/loot/lootgroup/LootObject.h"


// Imported class dependencies

#include "system/util/Vector.h"

#include "system/io/ObjectOutputStream.h"

#include "server/zone/managers/minigames/FishingManager.h"

#include "server/zone/objects/player/badges/Badges.h"

#include "engine/service/DatagramServiceThread.h"

#include "server/zone/objects/player/events/PlayerDisconnectEvent.h"

#include "server/zone/managers/professions/ProfessionManager.h"

#include "server/zone/managers/radial/RadialManager.h"

#include "server/zone/objects/area/ActiveArea.h"

#include "server/chat/ChatManager.h"

#include "engine/service/proto/BasePacketHandler.h"

#include "server/zone/objects/scene/variables/StringId.h"

#include "engine/core/Task.h"

#include "engine/core/ManagedObject.h"

#include "engine/service/proto/BasePacket.h"

#include "system/net/Socket.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/objects/player/events/PlayerRecoveryEvent.h"

#include "server/zone/objects/tangible/tool/CraftingTool.h"

#include "server/zone/managers/resource/ResourceManager.h"

#include "server/chat/room/ChatRoom.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "server/zone/managers/objectcontroller/ObjectController.h"

#include "server/zone/managers/city/CityManager.h"

#include "server/zone/managers/loot/LootManager.h"

#include "server/zone/managers/creature/CreatureManager.h"

#include "server/login/account/Account.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/player/ValidatedPosition.h"

#include "system/util/SortedVector.h"

#include "server/zone/managers/guild/GuildManager.h"

#include "server/zone/objects/cell/CellObject.h"

#include "system/lang/Time.h"

#include "system/thread/atomic/AtomicInteger.h"

#include "server/zone/managers/object/ObjectMap.h"

#include "engine/util/Facade.h"

#include "server/zone/objects/player/TradeContainer.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "system/util/VectorMap.h"

#include "server/login/account/AccountManager.h"

#include "server/zone/objects/tangible/tool/SurveyTool.h"

#include "server/zone/managers/vendor/VendorManager.h"

#include "server/zone/ZonePacketHandler.h"

#include "server/zone/managers/player/PlayerManager.h"

#include "system/lang/Exception.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/managers/mission/MissionManager.h"

#include "server/zone/managers/planet/MapLocationTable.h"

#include "engine/util/u3d/Quaternion.h"

#include "engine/util/u3d/Coordinate.h"

#include "server/zone/managers/minigames/GamblingManager.h"

#include "server/zone/managers/crafting/CraftingManager.h"

#include "server/zone/managers/creature/CreatureTemplateManager.h"

#include "server/zone/objects/building/BuildingObject.h"

#include "engine/stm/TransactionalReference.h"

#include "system/net/SocketAddress.h"

#include "server/zone/objects/tangible/sign/SignObject.h"

#include "server/zone/ZoneProcessServer.h"

#include "server/zone/Zone.h"

#include "system/net/Packet.h"

#include "server/zone/managers/sui/SuiManager.h"

#include "server/zone/managers/minigames/ForageManager.h"

#include "engine/service/proto/BaseClientProxy.h"

#include "server/zone/managers/holocron/HolocronManager.h"

#include "server/zone/ZoneHandler.h"

#include "server/zone/managers/name/NameManager.h"

#include "server/zone/objects/scene/variables/PendingTasksMap.h"

#include "engine/util/u3d/QuadTreeEntry.h"

#include "engine/util/u3d/QuadTree.h"

#include "server/zone/ZoneClientSession.h"

#include "server/zone/managers/object/ObjectManager.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "system/io/ObjectInputStream.h"

#include "server/zone/managers/planet/HeightMap.h"

#include "server/zone/managers/stringid/StringIdManager.h"

#include "engine/service/Message.h"

#include "engine/core/ObjectUpdateToDatabaseTask.h"

#include "server/zone/objects/player/sui/SuiBox.h"

#include "server/zone/managers/auction/AuctionManager.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/managers/planet/PlanetManager.h"

/*
 *	LootGroupObjectStub
 */

enum {RPC_CONTAINS__INT_ = 6,RPC_GET__INT_,RPC_PUT__INT_LOOTOBJECT_,RPC_SIZE__,RPC_GETMAXDROP__,RPC_GETWEIGHT__,RPC_GETLOOTGROUP__};

LootGroupObject::LootGroupObject(unsigned int group, int w, int max) : ManagedObject(DummyConstructorParameter::instance()) {
	LootGroupObjectImplementation* _implementation = new LootGroupObjectImplementation(group, w, max);
	ManagedObject::_setImplementation(_implementation);
	_implementation->_setStub(this);
}

LootGroupObject::LootGroupObject(DummyConstructorParameter* param) : ManagedObject(param) {
}

LootGroupObject::~LootGroupObject() {
}


bool LootGroupObject::contains(unsigned int objIndex) {
	LootGroupObjectImplementation* _implementation = (LootGroupObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CONTAINS__INT_);
		method.addUnsignedIntParameter(objIndex);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->contains(objIndex);
}

LootObject* LootGroupObject::get(unsigned int lootObjectID) {
	LootGroupObjectImplementation* _implementation = (LootGroupObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GET__INT_);
		method.addUnsignedIntParameter(lootObjectID);

		return (LootObject*) method.executeWithObjectReturn();
	} else
		return _implementation->get(lootObjectID);
}

void LootGroupObject::put(unsigned int index, LootObject* obj) {
	LootGroupObjectImplementation* _implementation = (LootGroupObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_PUT__INT_LOOTOBJECT_);
		method.addUnsignedIntParameter(index);
		method.addObjectParameter(obj);

		method.executeWithVoidReturn();
	} else
		_implementation->put(index, obj);
}

LootObject* LootGroupObject::selectLoot() {
	LootGroupObjectImplementation* _implementation = (LootGroupObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->selectLoot();
}

int LootGroupObject::size() {
	LootGroupObjectImplementation* _implementation = (LootGroupObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SIZE__);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->size();
}

int LootGroupObject::getMaxDrop() {
	LootGroupObjectImplementation* _implementation = (LootGroupObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETMAXDROP__);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getMaxDrop();
}

int LootGroupObject::getWeight() {
	LootGroupObjectImplementation* _implementation = (LootGroupObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETWEIGHT__);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getWeight();
}

unsigned int LootGroupObject::getLootGroup() {
	LootGroupObjectImplementation* _implementation = (LootGroupObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETLOOTGROUP__);

		return method.executeWithUnsignedIntReturn();
	} else
		return _implementation->getLootGroup();
}

DistributedObjectServant* LootGroupObject::_getImplementation() {

	_updated = true;
	return dynamic_cast<DistributedObjectServant*>(getForUpdate());}

void LootGroupObject::_setImplementation(DistributedObjectServant* servant) {
	setObject(dynamic_cast<LootGroupObjectImplementation*>(servant));
}

/*
 *	LootGroupObjectImplementation
 */

LootGroupObjectImplementation::LootGroupObjectImplementation(DummyConstructorParameter* param) : ManagedObjectImplementation(param) {
	_initializeImplementation();
}


LootGroupObjectImplementation::~LootGroupObjectImplementation() {
}


void LootGroupObjectImplementation::finalize() {
}

void LootGroupObjectImplementation::_initializeImplementation() {
	_setClassHelper(LootGroupObjectHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void LootGroupObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (LootGroupObject*) stub;
	ManagedObjectImplementation::_setStub(stub);
}

DistributedObjectStub* LootGroupObjectImplementation::_getStub() {
	return _this;
}

LootGroupObjectImplementation::operator const LootGroupObject*() {
	return _this;
}

Object* LootGroupObjectImplementation::clone() {
	return dynamic_cast<Object*>(new LootGroupObjectImplementation(*this));
}


void LootGroupObjectImplementation::lock(bool doLock) {
}

void LootGroupObjectImplementation::lock(ManagedObject* obj) {
}

void LootGroupObjectImplementation::rlock(bool doLock) {
}

void LootGroupObjectImplementation::wlock(bool doLock) {
}

void LootGroupObjectImplementation::wlock(ManagedObject* obj) {
}

void LootGroupObjectImplementation::unlock(bool doLock) {
}

void LootGroupObjectImplementation::runlock(bool doLock) {
}

void LootGroupObjectImplementation::_serializationHelperMethod() {
	ManagedObjectImplementation::_serializationHelperMethod();

	_setClassName("LootGroupObject");

}

void LootGroupObjectImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(LootGroupObjectImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool LootGroupObjectImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (ManagedObjectImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "lootObjects") {
		TypeInfo<VectorMap<unsigned int, ManagedReference<LootObject* > > >::parseFromBinaryStream(&lootObjects, stream);
		return true;
	}

	if (_name == "zoneServer") {
		TypeInfo<ManagedReference<ZoneServer* > >::parseFromBinaryStream(&zoneServer, stream);
		return true;
	}

	if (_name == "lootGroup") {
		TypeInfo<unsigned int >::parseFromBinaryStream(&lootGroup, stream);
		return true;
	}

	if (_name == "weight") {
		TypeInfo<int >::parseFromBinaryStream(&weight, stream);
		return true;
	}

	if (_name == "maxDrop") {
		TypeInfo<int >::parseFromBinaryStream(&maxDrop, stream);
		return true;
	}

	if (_name == "maxChance") {
		TypeInfo<int >::parseFromBinaryStream(&maxChance, stream);
		return true;
	}


	return false;
}

void LootGroupObjectImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = LootGroupObjectImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int LootGroupObjectImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "lootObjects";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<VectorMap<unsigned int, ManagedReference<LootObject* > > >::toBinaryStream(&lootObjects, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "zoneServer";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<ManagedReference<ZoneServer* > >::toBinaryStream(&zoneServer, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "lootGroup";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<unsigned int >::toBinaryStream(&lootGroup, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "weight";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<int >::toBinaryStream(&weight, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "maxDrop";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<int >::toBinaryStream(&maxDrop, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "maxChance";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<int >::toBinaryStream(&maxChance, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 6 + ManagedObjectImplementation::writeObjectMembers(stream);
}

LootGroupObjectImplementation::LootGroupObjectImplementation(unsigned int group, int w, int max) {
	_initializeImplementation();
	// server/zone/managers/loot/lootgroup/LootGroupObject.idl():  		lootObjects.setNullValue(null);
	(&lootObjects)->setNullValue(NULL);
	// server/zone/managers/loot/lootgroup/LootGroupObject.idl():  		lootGroup = group;
	lootGroup = group;
	// server/zone/managers/loot/lootgroup/LootGroupObject.idl():  		weight = w;
	weight = w;
	// server/zone/managers/loot/lootgroup/LootGroupObject.idl():  		maxDrop = max;
	maxDrop = max;
	// server/zone/managers/loot/lootgroup/LootGroupObject.idl():  		maxChance = 0;
	maxChance = 0;
	// server/zone/managers/loot/lootgroup/LootGroupObject.idl():  		Logger.setLoggingName("LootGroup");
	Logger::setLoggingName("LootGroup");
	// server/zone/managers/loot/lootgroup/LootGroupObject.idl():  		Logger.setLogging(true);
	Logger::setLogging(true);
	// server/zone/managers/loot/lootgroup/LootGroupObject.idl():  		Logger.setGlobalLogging(true);
	Logger::setGlobalLogging(true);
}

bool LootGroupObjectImplementation::contains(unsigned int objIndex) {
	// server/zone/managers/loot/lootgroup/LootGroupObject.idl():  		return lootObjects.contains(objIndex);
	return (&lootObjects)->contains(objIndex);
}

LootObject* LootGroupObjectImplementation::get(unsigned int lootObjectID) {
	// server/zone/managers/loot/lootgroup/LootGroupObject.idl():  		return lootObjects.get(lootObjectID);
	return (&lootObjects)->get(lootObjectID);
}

int LootGroupObjectImplementation::size() {
	// server/zone/managers/loot/lootgroup/LootGroupObject.idl():  		return lootObjects.size();
	return (&lootObjects)->size();
}

int LootGroupObjectImplementation::getMaxDrop() {
	// server/zone/managers/loot/lootgroup/LootGroupObject.idl():  		return maxDrop;
	return maxDrop;
}

int LootGroupObjectImplementation::getWeight() {
	// server/zone/managers/loot/lootgroup/LootGroupObject.idl():  		return weight;
	return weight;
}

unsigned int LootGroupObjectImplementation::getLootGroup() {
	// server/zone/managers/loot/lootgroup/LootGroupObject.idl():  		return lootGroup;
	return lootGroup;
}

/*
 *	LootGroupObjectAdapter
 */

LootGroupObjectAdapter::LootGroupObjectAdapter(LootGroupObjectImplementation* obj) : ManagedObjectAdapter(obj) {
}

Packet* LootGroupObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_CONTAINS__INT_:
		resp->insertBoolean(contains(inv->getUnsignedIntParameter()));
		break;
	case RPC_GET__INT_:
		resp->insertLong(get(inv->getUnsignedIntParameter())->_getObjectID());
		break;
	case RPC_PUT__INT_LOOTOBJECT_:
		put(inv->getUnsignedIntParameter(), (LootObject*) inv->getObjectParameter());
		break;
	case RPC_SIZE__:
		resp->insertSignedInt(size());
		break;
	case RPC_GETMAXDROP__:
		resp->insertSignedInt(getMaxDrop());
		break;
	case RPC_GETWEIGHT__:
		resp->insertSignedInt(getWeight());
		break;
	case RPC_GETLOOTGROUP__:
		resp->insertInt(getLootGroup());
		break;
	default:
		return NULL;
	}

	return resp;
}

bool LootGroupObjectAdapter::contains(unsigned int objIndex) {
	return ((LootGroupObjectImplementation*) impl)->contains(objIndex);
}

LootObject* LootGroupObjectAdapter::get(unsigned int lootObjectID) {
	return ((LootGroupObjectImplementation*) impl)->get(lootObjectID);
}

void LootGroupObjectAdapter::put(unsigned int index, LootObject* obj) {
	((LootGroupObjectImplementation*) impl)->put(index, obj);
}

int LootGroupObjectAdapter::size() {
	return ((LootGroupObjectImplementation*) impl)->size();
}

int LootGroupObjectAdapter::getMaxDrop() {
	return ((LootGroupObjectImplementation*) impl)->getMaxDrop();
}

int LootGroupObjectAdapter::getWeight() {
	return ((LootGroupObjectImplementation*) impl)->getWeight();
}

unsigned int LootGroupObjectAdapter::getLootGroup() {
	return ((LootGroupObjectImplementation*) impl)->getLootGroup();
}

/*
 *	LootGroupObjectHelper
 */

LootGroupObjectHelper* LootGroupObjectHelper::staticInitializer = LootGroupObjectHelper::instance();

LootGroupObjectHelper::LootGroupObjectHelper() {
	className = "LootGroupObject";

	Core::getObjectBroker()->registerClass(className, this);
}

void LootGroupObjectHelper::finalizeHelper() {
	LootGroupObjectHelper::finalize();
}

DistributedObject* LootGroupObjectHelper::instantiateObject() {
	return new LootGroupObject(DummyConstructorParameter::instance());
}

DistributedObjectServant* LootGroupObjectHelper::instantiateServant() {
	return new LootGroupObjectImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* LootGroupObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new LootGroupObjectAdapter((LootGroupObjectImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

