/*
 *	server/zone/objects/tangible/fishing/FishObject.cpp generated by engine3 IDL compiler 0.60
 */

#include "FishObject.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/Zone.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/ZoneServer.h"


// Imported class dependencies

#include "system/util/Vector.h"

#include "engine/util/ObserverEventMap.h"

#include "server/zone/managers/minigames/FishingManager.h"

#include "engine/service/DatagramServiceThread.h"

#include "server/zone/objects/player/events/PlayerDisconnectEvent.h"

#include "server/zone/managers/professions/ProfessionManager.h"

#include "server/zone/objects/manufactureschematic/craftingvalues/CraftingValues.h"

#include "server/zone/objects/group/GroupList.h"

#include "engine/core/ManagedObject.h"

#include "engine/service/proto/BasePacket.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/managers/resource/ResourceManager.h"

#include "server/zone/managers/objectcontroller/ObjectController.h"

#include "server/zone/objects/manufactureschematic/ManufactureSchematic.h"

#include "server/zone/managers/city/CityManager.h"

#include "server/zone/managers/creature/CreatureManager.h"

#include "server/zone/objects/creature/variables/CooldownTimerMap.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/managers/guild/GuildManager.h"

#include "server/zone/objects/cell/CellObject.h"

#include "system/thread/atomic/AtomicInteger.h"

#include "server/zone/objects/guild/GuildObject.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "system/util/VectorMap.h"

#include "system/lang/Exception.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/objects/scene/variables/DeltaVectorMap.h"

#include "server/zone/objects/group/GroupObject.h"

#include "server/zone/managers/crafting/CraftingManager.h"

#include "server/zone/objects/building/BuildingObject.h"

#include "system/net/SocketAddress.h"

#include "server/zone/ZoneProcessServer.h"

#include "system/net/Packet.h"

#include "server/zone/managers/minigames/ForageManager.h"

#include "server/zone/objects/intangible/ControlDevice.h"

#include "engine/service/proto/BaseClientProxy.h"

#include "server/zone/managers/holocron/HolocronManager.h"

#include "server/zone/objects/scene/variables/PendingTasksMap.h"

#include "engine/util/u3d/QuadTreeEntry.h"

#include "server/zone/ZoneClientSession.h"

#include "server/zone/managers/object/ObjectManager.h"

#include "system/io/ObjectInputStream.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "server/zone/objects/creature/buffs/Buff.h"

#include "engine/service/Message.h"

#include "server/zone/objects/player/sui/SuiBox.h"

#include "engine/util/Observer.h"

#include "system/io/ObjectOutputStream.h"

#include "server/zone/objects/scene/variables/DeltaVector.h"

#include "engine/service/proto/BaseMessage.h"

#include "server/zone/objects/creature/damageovertime/DamageOverTimeList.h"

#include "server/zone/objects/creature/SpeedMultiplierModChanges.h"

#include "server/zone/objects/player/badges/Badges.h"

#include "server/zone/managers/radial/RadialManager.h"

#include "server/zone/objects/area/ActiveArea.h"

#include "server/chat/ChatManager.h"

#include "engine/service/proto/BasePacketHandler.h"

#include "server/zone/objects/scene/variables/StringId.h"

#include "engine/core/Task.h"

#include "system/net/Socket.h"

#include "server/zone/objects/player/events/PlayerRecoveryEvent.h"

#include "server/zone/objects/tangible/tool/CraftingTool.h"

#include "server/chat/room/ChatRoom.h"

#include "server/zone/objects/creature/professions/SkillBox.h"

#include "engine/util/u3d/QuadTreeNode.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "server/zone/objects/scene/variables/CustomizationVariables.h"

#include "server/zone/managers/loot/LootManager.h"

#include "server/login/account/Account.h"

#include "system/util/SortedVector.h"

#include "server/zone/objects/player/ValidatedPosition.h"

#include "system/lang/Time.h"

#include "server/zone/managers/object/ObjectMap.h"

#include "engine/util/Facade.h"

#include "server/zone/objects/player/TradeContainer.h"

#include "server/zone/objects/draftschematic/DraftSchematic.h"

#include "server/login/account/AccountManager.h"

#include "server/zone/objects/tangible/tool/SurveyTool.h"

#include "server/zone/objects/creature/variables/CommandQueueAction.h"

#include "server/zone/managers/vendor/VendorManager.h"

#include "server/zone/ZonePacketHandler.h"

#include "server/zone/managers/player/PlayerManager.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "engine/util/Observable.h"

#include "server/zone/managers/planet/MapLocationTable.h"

#include "server/zone/managers/mission/MissionManager.h"

#include "engine/util/u3d/Quaternion.h"

#include "engine/util/u3d/Coordinate.h"

#include "server/zone/managers/minigames/GamblingManager.h"

#include "server/zone/objects/tangible/weapon/WeaponObject.h"

#include "server/zone/objects/creature/buffs/BuffList.h"

#include "server/zone/managers/creature/CreatureTemplateManager.h"

#include "server/zone/objects/creature/variables/SkillBoxList.h"

#include "engine/stm/TransactionalReference.h"

#include "server/zone/objects/tangible/sign/SignObject.h"

#include "server/zone/Zone.h"

#include "server/zone/managers/sui/SuiManager.h"

#include "server/zone/managers/name/NameManager.h"

#include "server/zone/ZoneHandler.h"

#include "engine/util/u3d/QuadTree.h"

#include "server/zone/managers/planet/HeightMap.h"

#include "server/zone/managers/stringid/StringIdManager.h"

#include "server/chat/StringIdChatParameter.h"

#include "server/zone/objects/manufactureschematic/IngredientSlots.h"

#include "engine/core/ObjectUpdateToDatabaseTask.h"

#include "server/zone/managers/auction/AuctionManager.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/managers/planet/PlanetManager.h"

/*
 *	FishObjectStub
 */

enum {RPC_INITIALIZETRANSIENTMEMBERS__ = 6,RPC_SETATTRIBUTES__STRING_INT_STRING_FLOAT_,RPC_FILLOBJECTMENURESPONSE__OBJECTMENURESPONSE_PLAYERCREATURE_,RPC_HANDLEOBJECTMENUSELECT__PLAYERCREATURE_BYTE_,RPC_FILLATTRIBUTELIST__ATTRIBUTELISTMESSAGE_PLAYERCREATURE_,RPC_FILET__PLAYERCREATURE_};

FishObject::FishObject() : TangibleObject(DummyConstructorParameter::instance()) {
	FishObjectImplementation* _implementation = new FishObjectImplementation();
	ManagedObject::_setImplementation(_implementation);
	_implementation->_setStub(this);
}

FishObject::FishObject(DummyConstructorParameter* param) : TangibleObject(param) {
}

FishObject::~FishObject() {
}


void FishObject::initializeTransientMembers() {
	FishObjectImplementation* _implementation = (FishObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZETRANSIENTMEMBERS__);

		method.executeWithVoidReturn();
	} else
		_implementation->initializeTransientMembers();
}

void FishObject::setAttributes(String& playerName, int planetID, String& timestamp, float fishLength) {
	FishObjectImplementation* _implementation = (FishObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETATTRIBUTES__STRING_INT_STRING_FLOAT_);
		method.addAsciiParameter(playerName);
		method.addSignedIntParameter(planetID);
		method.addAsciiParameter(timestamp);
		method.addFloatParameter(fishLength);

		method.executeWithVoidReturn();
	} else
		_implementation->setAttributes(playerName, planetID, timestamp, fishLength);
}

void FishObject::fillObjectMenuResponse(ObjectMenuResponse* menuResponse, PlayerCreature* player) {
	FishObjectImplementation* _implementation = (FishObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_FILLOBJECTMENURESPONSE__OBJECTMENURESPONSE_PLAYERCREATURE_);
		method.addObjectParameter(menuResponse);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->fillObjectMenuResponse(menuResponse, player);
}

int FishObject::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	FishObjectImplementation* _implementation = (FishObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_HANDLEOBJECTMENUSELECT__PLAYERCREATURE_BYTE_);
		method.addObjectParameter(player);
		method.addByteParameter(selectedID);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->handleObjectMenuSelect(player, selectedID);
}

void FishObject::fillAttributeList(AttributeListMessage* msg, PlayerCreature* object) {
	FishObjectImplementation* _implementation = (FishObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_FILLATTRIBUTELIST__ATTRIBUTELISTMESSAGE_PLAYERCREATURE_);
		method.addObjectParameter(msg);
		method.addObjectParameter(object);

		method.executeWithVoidReturn();
	} else
		_implementation->fillAttributeList(msg, object);
}

void FishObject::filet(PlayerCreature* player) {
	FishObjectImplementation* _implementation = (FishObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_FILET__PLAYERCREATURE_);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->filet(player);
}

DistributedObjectServant* FishObject::_getImplementation() {

	_updated = true;
	return dynamic_cast<DistributedObjectServant*>(getForUpdate());}

void FishObject::_setImplementation(DistributedObjectServant* servant) {
	setObject(dynamic_cast<FishObjectImplementation*>(servant));
}

/*
 *	FishObjectImplementation
 */

FishObjectImplementation::FishObjectImplementation(DummyConstructorParameter* param) : TangibleObjectImplementation(param) {
	_initializeImplementation();
}


FishObjectImplementation::~FishObjectImplementation() {
}


void FishObjectImplementation::finalize() {
}

void FishObjectImplementation::_initializeImplementation() {
	_setClassHelper(FishObjectHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void FishObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (FishObject*) stub;
	TangibleObjectImplementation::_setStub(stub);
}

DistributedObjectStub* FishObjectImplementation::_getStub() {
	return _this;
}

FishObjectImplementation::operator const FishObject*() {
	return _this;
}

Object* FishObjectImplementation::clone() {
	return dynamic_cast<Object*>(new FishObjectImplementation(*this));
}


void FishObjectImplementation::lock(bool doLock) {
}

void FishObjectImplementation::lock(ManagedObject* obj) {
}

void FishObjectImplementation::rlock(bool doLock) {
}

void FishObjectImplementation::wlock(bool doLock) {
}

void FishObjectImplementation::wlock(ManagedObject* obj) {
}

void FishObjectImplementation::unlock(bool doLock) {
}

void FishObjectImplementation::runlock(bool doLock) {
}

void FishObjectImplementation::_serializationHelperMethod() {
	TangibleObjectImplementation::_serializationHelperMethod();

	_setClassName("FishObject");

}

void FishObjectImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(FishObjectImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool FishObjectImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (TangibleObjectImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "player") {
		TypeInfo<String >::parseFromBinaryStream(&player, stream);
		return true;
	}

	if (_name == "planet") {
		TypeInfo<int >::parseFromBinaryStream(&planet, stream);
		return true;
	}

	if (_name == "timeCaught") {
		TypeInfo<String >::parseFromBinaryStream(&timeCaught, stream);
		return true;
	}

	if (_name == "length") {
		TypeInfo<float >::parseFromBinaryStream(&length, stream);
		return true;
	}


	return false;
}

void FishObjectImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = FishObjectImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int FishObjectImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "player";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<String >::toBinaryStream(&player, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "planet";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<int >::toBinaryStream(&planet, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "timeCaught";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<String >::toBinaryStream(&timeCaught, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "length";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&length, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 4 + TangibleObjectImplementation::writeObjectMembers(stream);
}

FishObjectImplementation::FishObjectImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/fishing/FishObject.idl():  		Logger.setLoggingName("FishObject");
	Logger::setLoggingName("FishObject");
	// server/zone/objects/tangible/fishing/FishObject.idl():  		player = "";
	player = "";
	// server/zone/objects/tangible/fishing/FishObject.idl():  		planet = 0;
	planet = 0;
	// server/zone/objects/tangible/fishing/FishObject.idl():  		timeCaught = "";
	timeCaught = "";
	// server/zone/objects/tangible/fishing/FishObject.idl():  		length = 0.0;
	length = 0.0;
}

void FishObjectImplementation::initializeTransientMembers() {
	// server/zone/objects/tangible/fishing/FishObject.idl():  		super.initializeTransientMembers();
	TangibleObjectImplementation::initializeTransientMembers();
	// server/zone/objects/tangible/fishing/FishObject.idl():  		Logger.setLoggingName("FishObject");
	Logger::setLoggingName("FishObject");
}

void FishObjectImplementation::setAttributes(String& playerName, int planetID, String& timestamp, float fishLength) {
	// server/zone/objects/tangible/fishing/FishObject.idl():  		player = playerName;
	player = playerName;
	// server/zone/objects/tangible/fishing/FishObject.idl():  		planet = planetID;
	planet = planetID;
	// server/zone/objects/tangible/fishing/FishObject.idl():  		timeCaught = timestamp;
	timeCaught = timestamp;
	// server/zone/objects/tangible/fishing/FishObject.idl():  		length = fishLength;
	length = fishLength;
}

/*
 *	FishObjectAdapter
 */

FishObjectAdapter::FishObjectAdapter(FishObjectImplementation* obj) : TangibleObjectAdapter(obj) {
}

Packet* FishObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_INITIALIZETRANSIENTMEMBERS__:
		initializeTransientMembers();
		break;
	case RPC_SETATTRIBUTES__STRING_INT_STRING_FLOAT_:
		setAttributes(inv->getAsciiParameter(_param0_setAttributes__String_int_String_float_), inv->getSignedIntParameter(), inv->getAsciiParameter(_param2_setAttributes__String_int_String_float_), inv->getFloatParameter());
		break;
	case RPC_FILLOBJECTMENURESPONSE__OBJECTMENURESPONSE_PLAYERCREATURE_:
		fillObjectMenuResponse((ObjectMenuResponse*) inv->getObjectParameter(), (PlayerCreature*) inv->getObjectParameter());
		break;
	case RPC_HANDLEOBJECTMENUSELECT__PLAYERCREATURE_BYTE_:
		resp->insertSignedInt(handleObjectMenuSelect((PlayerCreature*) inv->getObjectParameter(), inv->getByteParameter()));
		break;
	case RPC_FILLATTRIBUTELIST__ATTRIBUTELISTMESSAGE_PLAYERCREATURE_:
		fillAttributeList((AttributeListMessage*) inv->getObjectParameter(), (PlayerCreature*) inv->getObjectParameter());
		break;
	case RPC_FILET__PLAYERCREATURE_:
		filet((PlayerCreature*) inv->getObjectParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void FishObjectAdapter::initializeTransientMembers() {
	((FishObjectImplementation*) impl)->initializeTransientMembers();
}

void FishObjectAdapter::setAttributes(String& playerName, int planetID, String& timestamp, float fishLength) {
	((FishObjectImplementation*) impl)->setAttributes(playerName, planetID, timestamp, fishLength);
}

void FishObjectAdapter::fillObjectMenuResponse(ObjectMenuResponse* menuResponse, PlayerCreature* player) {
	((FishObjectImplementation*) impl)->fillObjectMenuResponse(menuResponse, player);
}

int FishObjectAdapter::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	return ((FishObjectImplementation*) impl)->handleObjectMenuSelect(player, selectedID);
}

void FishObjectAdapter::fillAttributeList(AttributeListMessage* msg, PlayerCreature* object) {
	((FishObjectImplementation*) impl)->fillAttributeList(msg, object);
}

void FishObjectAdapter::filet(PlayerCreature* player) {
	((FishObjectImplementation*) impl)->filet(player);
}

/*
 *	FishObjectHelper
 */

FishObjectHelper* FishObjectHelper::staticInitializer = FishObjectHelper::instance();

FishObjectHelper::FishObjectHelper() {
	className = "FishObject";

	Core::getObjectBroker()->registerClass(className, this);
}

void FishObjectHelper::finalizeHelper() {
	FishObjectHelper::finalize();
}

DistributedObject* FishObjectHelper::instantiateObject() {
	return new FishObject(DummyConstructorParameter::instance());
}

DistributedObjectServant* FishObjectHelper::instantiateServant() {
	return new FishObjectImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* FishObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new FishObjectAdapter((FishObjectImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

