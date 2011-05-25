/*
 *	server/zone/objects/tangible/pharmaceutical/StimPack.cpp generated by engine3 IDL compiler 0.60
 */

#include "StimPack.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/Zone.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/objects/manufactureschematic/ManufactureSchematic.h"


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
 *	StimPackStub
 */

enum {RPC_CALCULATEPOWER__CREATUREOBJECT_CREATUREOBJECT_BOOL_,RPC_HANDLEOBJECTMENUSELECT__PLAYERCREATURE_BYTE_,RPC_GETEFFECTIVENESS__,RPC_ISSTIMPACK__};

StimPack::StimPack() : PharmaceuticalObject(DummyConstructorParameter::instance()) {
	StimPackImplementation* _implementation = new StimPackImplementation();
	ManagedObject::_setImplementation(_implementation);
	_implementation->_setStub(this);
}

StimPack::StimPack(DummyConstructorParameter* param) : PharmaceuticalObject(param) {
}

StimPack::~StimPack() {
}


void StimPack::updateCraftingValues(ManufactureSchematic* schematic) {
	StimPackImplementation* _implementation = (StimPackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->updateCraftingValues(schematic);
}

void StimPack::loadTemplateData(SharedObjectTemplate* templateData) {
	StimPackImplementation* _implementation = (StimPackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->loadTemplateData(templateData);
}

unsigned int StimPack::calculatePower(CreatureObject* healer, CreatureObject* patient, bool applyBattleFatigue) {
	StimPackImplementation* _implementation = (StimPackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CALCULATEPOWER__CREATUREOBJECT_CREATUREOBJECT_BOOL_);
		method.addObjectParameter(healer);
		method.addObjectParameter(patient);
		method.addBooleanParameter(applyBattleFatigue);

		return method.executeWithUnsignedIntReturn();
	} else
		return _implementation->calculatePower(healer, patient, applyBattleFatigue);
}

int StimPack::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	StimPackImplementation* _implementation = (StimPackImplementation*) _getImplementation();
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

void StimPack::fillAttributeList(AttributeListMessage* msg, PlayerCreature* object) {
	StimPackImplementation* _implementation = (StimPackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->fillAttributeList(msg, object);
}

float StimPack::getEffectiveness() {
	StimPackImplementation* _implementation = (StimPackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETEFFECTIVENESS__);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getEffectiveness();
}

bool StimPack::isStimPack() {
	StimPackImplementation* _implementation = (StimPackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISSTIMPACK__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isStimPack();
}

DistributedObjectServant* StimPack::_getImplementation() {

	_updated = true;
	return dynamic_cast<DistributedObjectServant*>(getForUpdate());}

void StimPack::_setImplementation(DistributedObjectServant* servant) {
	setObject(dynamic_cast<StimPackImplementation*>(servant));
}

/*
 *	StimPackImplementation
 */

StimPackImplementation::StimPackImplementation(DummyConstructorParameter* param) : PharmaceuticalObjectImplementation(param) {
	_initializeImplementation();
}


StimPackImplementation::~StimPackImplementation() {
}


void StimPackImplementation::finalize() {
}

void StimPackImplementation::_initializeImplementation() {
	_setClassHelper(StimPackHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void StimPackImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (StimPack*) stub;
	PharmaceuticalObjectImplementation::_setStub(stub);
}

DistributedObjectStub* StimPackImplementation::_getStub() {
	return _this;
}

StimPackImplementation::operator const StimPack*() {
	return _this;
}

Object* StimPackImplementation::clone() {
	return dynamic_cast<Object*>(new StimPackImplementation(*this));
}


void StimPackImplementation::lock(bool doLock) {
}

void StimPackImplementation::lock(ManagedObject* obj) {
}

void StimPackImplementation::rlock(bool doLock) {
}

void StimPackImplementation::wlock(bool doLock) {
}

void StimPackImplementation::wlock(ManagedObject* obj) {
}

void StimPackImplementation::unlock(bool doLock) {
}

void StimPackImplementation::runlock(bool doLock) {
}

void StimPackImplementation::_serializationHelperMethod() {
	PharmaceuticalObjectImplementation::_serializationHelperMethod();

	_setClassName("StimPack");

}

void StimPackImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(StimPackImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool StimPackImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (PharmaceuticalObjectImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "effectiveness") {
		TypeInfo<float >::parseFromBinaryStream(&effectiveness, stream);
		return true;
	}


	return false;
}

void StimPackImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = StimPackImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int StimPackImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "effectiveness";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&effectiveness, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 1 + PharmaceuticalObjectImplementation::writeObjectMembers(stream);
}

StimPackImplementation::StimPackImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		setLoggingName("StimPack");
	setLoggingName("StimPack");
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		effectiveness = 0;
	effectiveness = 0;
}

void StimPackImplementation::updateCraftingValues(ManufactureSchematic* schematic) {
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		CraftingValues craftingValues = schematic.getCraftingValues();
	CraftingValues* craftingValues = schematic->getCraftingValues();
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		effectiveness = craftingValues.getCurrentValue("power");
	effectiveness = craftingValues->getCurrentValue("power");
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		super.medicineUseRequired = craftingValues.getCurrentValue("skillmodmin");
	PharmaceuticalObjectImplementation::medicineUseRequired = craftingValues->getCurrentValue("skillmodmin");
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		setUseCount(craftingValues.getCurrentValue("charges"));
	setUseCount(craftingValues->getCurrentValue("charges"));
}

void StimPackImplementation::loadTemplateData(SharedObjectTemplate* templateData) {
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		super.loadTemplateData(templateData);
	PharmaceuticalObjectImplementation::loadTemplateData(templateData);
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		StimPackTemplate 
	if (!templateData->isStimPackTemplate())	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  			return;
	return;
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		StimPackTemplate stimPackTemplate = (StimPackTemplate) templateData;
	StimPackTemplate* stimPackTemplate = (StimPackTemplate*) templateData;
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		effectiveness = stimPackTemplate.getEffectiveness();
	effectiveness = stimPackTemplate->getEffectiveness();
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		super.medicineUseRequired = stimPackTemplate.getMedicineUse();
	PharmaceuticalObjectImplementation::medicineUseRequired = stimPackTemplate->getMedicineUse();
}

unsigned int StimPackImplementation::calculatePower(CreatureObject* healer, CreatureObject* patient, bool applyBattleFatigue) {
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		float power = getEffectiveness();
	float power = getEffectiveness();
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		float 
	if (applyBattleFatigue){
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  			power = power - power * patient.calculateBFRatio();
	power = power - power * patient->calculateBFRatio();
}
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		float modSkill = (float) healer.getSkillMod("healing_injury_treatment");
	float modSkill = (float) healer->getSkillMod("healing_injury_treatment");
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		return (100 + modSkill) / 100 * power;
	return (100 + modSkill) / 100 * power;
}

int StimPackImplementation::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		if 
	if (selectedID != 20)	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  			return 1;
	return 1;
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		}
	if (player->getSkillMod("healing_ability") < PharmaceuticalObjectImplementation::medicineUseRequired){
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  			player.sendSystemMessage("error_message", "insufficient_skill");
	player->sendSystemMessage("error_message", "insufficient_skill");
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  			return 0;
	return 0;
}

	else {
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  			string command = "/healdamage ";
	String command = "/healdamage ";
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  			player.sendExecuteConsoleCommand(command + String.valueOf(super.getObjectID()));
	player->sendExecuteConsoleCommand(command + String::valueOf(PharmaceuticalObjectImplementation::getObjectID()));
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  			return 0;
	return 0;
}
}

void StimPackImplementation::fillAttributeList(AttributeListMessage* msg, PlayerCreature* object) {
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		super.fillAttributeList(msg, object);
	PharmaceuticalObjectImplementation::fillAttributeList(msg, object);
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		msg.insertAttribute("examine_heal_damage_health", Math.getPrecision(effectiveness, 0));
	msg->insertAttribute("examine_heal_damage_health", Math::getPrecision(effectiveness, 0));
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		msg.insertAttribute("examine_heal_damage_action", Math.getPrecision(effectiveness, 0));
	msg->insertAttribute("examine_heal_damage_action", Math::getPrecision(effectiveness, 0));
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		msg.insertAttribute("healing_ability", super.medicineUseRequired);
	msg->insertAttribute("healing_ability", PharmaceuticalObjectImplementation::medicineUseRequired);
}

float StimPackImplementation::getEffectiveness() {
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		return effectiveness;
	return effectiveness;
}

bool StimPackImplementation::isStimPack() {
	// server/zone/objects/tangible/pharmaceutical/StimPack.idl():  		return true;
	return true;
}

/*
 *	StimPackAdapter
 */

StimPackAdapter::StimPackAdapter(StimPackImplementation* obj) : PharmaceuticalObjectAdapter(obj) {
}

Packet* StimPackAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_CALCULATEPOWER__CREATUREOBJECT_CREATUREOBJECT_BOOL_:
		resp->insertInt(calculatePower((CreatureObject*) inv->getObjectParameter(), (CreatureObject*) inv->getObjectParameter(), inv->getBooleanParameter()));
		break;
	case RPC_HANDLEOBJECTMENUSELECT__PLAYERCREATURE_BYTE_:
		resp->insertSignedInt(handleObjectMenuSelect((PlayerCreature*) inv->getObjectParameter(), inv->getByteParameter()));
		break;
	case RPC_GETEFFECTIVENESS__:
		resp->insertFloat(getEffectiveness());
		break;
	case RPC_ISSTIMPACK__:
		resp->insertBoolean(isStimPack());
		break;
	default:
		return NULL;
	}

	return resp;
}

unsigned int StimPackAdapter::calculatePower(CreatureObject* healer, CreatureObject* patient, bool applyBattleFatigue) {
	return ((StimPackImplementation*) impl)->calculatePower(healer, patient, applyBattleFatigue);
}

int StimPackAdapter::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	return ((StimPackImplementation*) impl)->handleObjectMenuSelect(player, selectedID);
}

float StimPackAdapter::getEffectiveness() {
	return ((StimPackImplementation*) impl)->getEffectiveness();
}

bool StimPackAdapter::isStimPack() {
	return ((StimPackImplementation*) impl)->isStimPack();
}

/*
 *	StimPackHelper
 */

StimPackHelper* StimPackHelper::staticInitializer = StimPackHelper::instance();

StimPackHelper::StimPackHelper() {
	className = "StimPack";

	Core::getObjectBroker()->registerClass(className, this);
}

void StimPackHelper::finalizeHelper() {
	StimPackHelper::finalize();
}

DistributedObject* StimPackHelper::instantiateObject() {
	return new StimPack(DummyConstructorParameter::instance());
}

DistributedObjectServant* StimPackHelper::instantiateServant() {
	return new StimPackImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* StimPackHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new StimPackAdapter((StimPackImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

