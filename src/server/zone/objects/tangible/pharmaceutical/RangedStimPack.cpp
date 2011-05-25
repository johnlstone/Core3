/*
 *	server/zone/objects/tangible/pharmaceutical/RangedStimPack.cpp generated by engine3 IDL compiler 0.60
 */

#include "RangedStimPack.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/Zone.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/objects/creature/CreatureObject.h"

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
 *	RangedStimPackStub
 */

enum {RPC_HANDLEOBJECTMENUSELECT__PLAYERCREATURE_BYTE_,RPC_CALCULATEPOWER__CREATUREOBJECT_CREATUREOBJECT_BOOL_,RPC_GETRANGE__CREATUREOBJECT_,RPC_GETEFFECTIVENESS__,RPC_GETAREA__,RPC_ISAREA__,RPC_GETRANGEMOD__,RPC_ISRANGEDSTIMPACK__};

RangedStimPack::RangedStimPack() : StimPack(DummyConstructorParameter::instance()) {
	RangedStimPackImplementation* _implementation = new RangedStimPackImplementation();
	ManagedObject::_setImplementation(_implementation);
	_implementation->_setStub(this);
}

RangedStimPack::RangedStimPack(DummyConstructorParameter* param) : StimPack(param) {
}

RangedStimPack::~RangedStimPack() {
}


void RangedStimPack::updateCraftingValues(ManufactureSchematic* schematic) {
	RangedStimPackImplementation* _implementation = (RangedStimPackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->updateCraftingValues(schematic);
}

void RangedStimPack::fillAttributeList(AttributeListMessage* msg, PlayerCreature* object) {
	RangedStimPackImplementation* _implementation = (RangedStimPackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->fillAttributeList(msg, object);
}

int RangedStimPack::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	RangedStimPackImplementation* _implementation = (RangedStimPackImplementation*) _getImplementation();
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

void RangedStimPack::loadTemplateData(SharedObjectTemplate* templateData) {
	RangedStimPackImplementation* _implementation = (RangedStimPackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->loadTemplateData(templateData);
}

unsigned int RangedStimPack::calculatePower(CreatureObject* healer, CreatureObject* patient, bool applyBattleFatigue) {
	RangedStimPackImplementation* _implementation = (RangedStimPackImplementation*) _getImplementation();
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

float RangedStimPack::getRange(CreatureObject* creature) {
	RangedStimPackImplementation* _implementation = (RangedStimPackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETRANGE__CREATUREOBJECT_);
		method.addObjectParameter(creature);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getRange(creature);
}

float RangedStimPack::getEffectiveness() {
	RangedStimPackImplementation* _implementation = (RangedStimPackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETEFFECTIVENESS__);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getEffectiveness();
}

float RangedStimPack::getArea() {
	RangedStimPackImplementation* _implementation = (RangedStimPackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETAREA__);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getArea();
}

bool RangedStimPack::isArea() {
	RangedStimPackImplementation* _implementation = (RangedStimPackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISAREA__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isArea();
}

float RangedStimPack::getRangeMod() {
	RangedStimPackImplementation* _implementation = (RangedStimPackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETRANGEMOD__);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getRangeMod();
}

bool RangedStimPack::isRangedStimPack() {
	RangedStimPackImplementation* _implementation = (RangedStimPackImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISRANGEDSTIMPACK__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isRangedStimPack();
}

DistributedObjectServant* RangedStimPack::_getImplementation() {

	_updated = true;
	return dynamic_cast<DistributedObjectServant*>(getForUpdate());}

void RangedStimPack::_setImplementation(DistributedObjectServant* servant) {
	setObject(dynamic_cast<RangedStimPackImplementation*>(servant));
}

/*
 *	RangedStimPackImplementation
 */

RangedStimPackImplementation::RangedStimPackImplementation(DummyConstructorParameter* param) : StimPackImplementation(param) {
	_initializeImplementation();
}


RangedStimPackImplementation::~RangedStimPackImplementation() {
}


void RangedStimPackImplementation::finalize() {
}

void RangedStimPackImplementation::_initializeImplementation() {
	_setClassHelper(RangedStimPackHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void RangedStimPackImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (RangedStimPack*) stub;
	StimPackImplementation::_setStub(stub);
}

DistributedObjectStub* RangedStimPackImplementation::_getStub() {
	return _this;
}

RangedStimPackImplementation::operator const RangedStimPack*() {
	return _this;
}

Object* RangedStimPackImplementation::clone() {
	return dynamic_cast<Object*>(new RangedStimPackImplementation(*this));
}


void RangedStimPackImplementation::lock(bool doLock) {
}

void RangedStimPackImplementation::lock(ManagedObject* obj) {
}

void RangedStimPackImplementation::rlock(bool doLock) {
}

void RangedStimPackImplementation::wlock(bool doLock) {
}

void RangedStimPackImplementation::wlock(ManagedObject* obj) {
}

void RangedStimPackImplementation::unlock(bool doLock) {
}

void RangedStimPackImplementation::runlock(bool doLock) {
}

void RangedStimPackImplementation::_serializationHelperMethod() {
	StimPackImplementation::_serializationHelperMethod();

	_setClassName("RangedStimPack");

}

void RangedStimPackImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(RangedStimPackImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool RangedStimPackImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (StimPackImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "range") {
		TypeInfo<float >::parseFromBinaryStream(&range, stream);
		return true;
	}

	if (_name == "area") {
		TypeInfo<float >::parseFromBinaryStream(&area, stream);
		return true;
	}

	if (_name == "rangeMod") {
		TypeInfo<float >::parseFromBinaryStream(&rangeMod, stream);
		return true;
	}


	return false;
}

void RangedStimPackImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = RangedStimPackImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int RangedStimPackImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "range";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&range, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "area";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&area, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "rangeMod";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<float >::toBinaryStream(&rangeMod, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 3 + StimPackImplementation::writeObjectMembers(stream);
}

RangedStimPackImplementation::RangedStimPackImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  		setLoggingName("RangedStimPack");
	setLoggingName("RangedStimPack");
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  		area = 0;
	area = 0;
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  		range = 0;
	range = 0;
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  		rangeMod = 0;
	rangeMod = 0;
}

void RangedStimPackImplementation::updateCraftingValues(ManufactureSchematic* schematic) {
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  		CraftingValues craftingValues = schematic.getCraftingValues();
	CraftingValues* craftingValues = schematic->getCraftingValues();
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  		super.effectiveness = craftingValues.getCurrentValue("power");
	StimPackImplementation::effectiveness = craftingValues->getCurrentValue("power");
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  		super.medicineUseRequired = craftingValues.getCurrentValue("skillmodmin");
	StimPackImplementation::medicineUseRequired = craftingValues->getCurrentValue("skillmodmin");
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  		setUseCount(craftingValues.getCurrentValue("charges"));
	setUseCount(craftingValues->getCurrentValue("charges"));
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  		range = craftingValues.getCurrentValue("range");
	range = craftingValues->getCurrentValue("range");
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  	}
	if (craftingValues->hasProperty("area")){
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  			area = craftingValues.getCurrentValue("area");
	area = craftingValues->getCurrentValue("area");
}
}

void RangedStimPackImplementation::fillAttributeList(AttributeListMessage* msg, PlayerCreature* object) {
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  		msg.insertAttribute("examine_heal_damage_health", Math.getPrecision(super.effectiveness, 0));
	msg->insertAttribute("examine_heal_damage_health", Math::getPrecision(StimPackImplementation::effectiveness, 0));
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  		msg.insertAttribute("examine_heal_damage_action", Math.getPrecision(super.effectiveness, 0));
	msg->insertAttribute("examine_heal_damage_action", Math::getPrecision(StimPackImplementation::effectiveness, 0));
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  		msg.insertAttribute("examine_heal_range", Math.getPrecision(range, 0));
	msg->insertAttribute("examine_heal_range", Math::getPrecision(range, 0));
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  		}
	if (isArea()){
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  			msg.insertAttribute("examine_heal_area", Math.getPrecision(area, 0));
	msg->insertAttribute("examine_heal_area", Math::getPrecision(area, 0));
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  			msg.insertAttribute("combat_healing_ability", super.medicineUseRequired);
	msg->insertAttribute("combat_healing_ability", StimPackImplementation::medicineUseRequired);
}

	else {
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  			msg.insertAttribute("combat_healing_ability", super.medicineUseRequired);
	msg->insertAttribute("combat_healing_ability", StimPackImplementation::medicineUseRequired);
}
}

int RangedStimPackImplementation::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  		if 
	if (selectedID != 20)	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  			return 1;
	return 1;
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  		}
	if (player->getSkillMod("combat_healing_ability") < StimPackImplementation::medicineUseRequired){
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  			player.sendSystemMessage("error_message", "insufficient_skill");
	player->sendSystemMessage("error_message", "insufficient_skill");
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  			return 0;
	return 0;
}

	else {
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  			string command = "/healdamage ";
	String command = "/healdamage ";
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  			player.sendExecuteConsoleCommand(command + String.valueOf(super.getObjectID()));
	player->sendExecuteConsoleCommand(command + String::valueOf(StimPackImplementation::getObjectID()));
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  			return 0;
	return 0;
}
}

void RangedStimPackImplementation::loadTemplateData(SharedObjectTemplate* templateData) {
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  		super.loadTemplateData(templateData);
	StimPackImplementation::loadTemplateData(templateData);
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  		RangedStimPackTemplate 
	if (!templateData->isRangedStimPackTemplate())	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  			return;
	return;
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  		RangedStimPackTemplate stimPackTemplate = (RangedStimPackTemplate) templateData;
	RangedStimPackTemplate* stimPackTemplate = (RangedStimPackTemplate*) templateData;
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  		super.effectiveness = stimPackTemplate.getEffectiveness();
	StimPackImplementation::effectiveness = stimPackTemplate->getEffectiveness();
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  		super.medicineUseRequired = stimPackTemplate.getMedicineUse();
	StimPackImplementation::medicineUseRequired = stimPackTemplate->getMedicineUse();
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  		area = stimPackTemplate.getArea();
	area = stimPackTemplate->getArea();
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  		range = stimPackTemplate.getRange();
	range = stimPackTemplate->getRange();
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  		rangeMod = stimPackTemplate.getRangeMod();
	rangeMod = stimPackTemplate->getRangeMod();
}

unsigned int RangedStimPackImplementation::calculatePower(CreatureObject* healer, CreatureObject* patient, bool applyBattleFatigue) {
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  		float power = getEffectiveness();
	float power = getEffectiveness();
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  		float 
	if (applyBattleFatigue){
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  			power = power - power * patient.calculateBFRatio();
	power = power - power * patient->calculateBFRatio();
}
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  		float modSkill = (float) healer.getSkillMod("combat_medic_effectiveness");
	float modSkill = (float) healer->getSkillMod("combat_medic_effectiveness");
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  		return (100 + modSkill) / 100 * power;
	return (100 + modSkill) / 100 * power;
}

float RangedStimPackImplementation::getRange(CreatureObject* creature) {
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  		float modSkill = 0;
	float modSkill = 0;
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  		float 
	if (creature != NULL){
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  			modSkill = creature.getSkillMod("healing_range");
	modSkill = creature->getSkillMod("healing_range");
}
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  		float value = (100 + rangeMod * modSkill) / 100 * range;
	float value = (100 + rangeMod * modSkill) / 100 * range;
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  		return value;
	return value;
}

float RangedStimPackImplementation::getEffectiveness() {
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  		return super.effectiveness;
	return StimPackImplementation::effectiveness;
}

float RangedStimPackImplementation::getArea() {
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  		return area;
	return area;
}

bool RangedStimPackImplementation::isArea() {
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  		return area != 0;
	return area != 0;
}

float RangedStimPackImplementation::getRangeMod() {
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  		return rangeMod;
	return rangeMod;
}

bool RangedStimPackImplementation::isRangedStimPack() {
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl():  		return true;
	return true;
}

/*
 *	RangedStimPackAdapter
 */

RangedStimPackAdapter::RangedStimPackAdapter(RangedStimPackImplementation* obj) : StimPackAdapter(obj) {
}

Packet* RangedStimPackAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_HANDLEOBJECTMENUSELECT__PLAYERCREATURE_BYTE_:
		resp->insertSignedInt(handleObjectMenuSelect((PlayerCreature*) inv->getObjectParameter(), inv->getByteParameter()));
		break;
	case RPC_CALCULATEPOWER__CREATUREOBJECT_CREATUREOBJECT_BOOL_:
		resp->insertInt(calculatePower((CreatureObject*) inv->getObjectParameter(), (CreatureObject*) inv->getObjectParameter(), inv->getBooleanParameter()));
		break;
	case RPC_GETRANGE__CREATUREOBJECT_:
		resp->insertFloat(getRange((CreatureObject*) inv->getObjectParameter()));
		break;
	case RPC_GETEFFECTIVENESS__:
		resp->insertFloat(getEffectiveness());
		break;
	case RPC_GETAREA__:
		resp->insertFloat(getArea());
		break;
	case RPC_ISAREA__:
		resp->insertBoolean(isArea());
		break;
	case RPC_GETRANGEMOD__:
		resp->insertFloat(getRangeMod());
		break;
	case RPC_ISRANGEDSTIMPACK__:
		resp->insertBoolean(isRangedStimPack());
		break;
	default:
		return NULL;
	}

	return resp;
}

int RangedStimPackAdapter::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	return ((RangedStimPackImplementation*) impl)->handleObjectMenuSelect(player, selectedID);
}

unsigned int RangedStimPackAdapter::calculatePower(CreatureObject* healer, CreatureObject* patient, bool applyBattleFatigue) {
	return ((RangedStimPackImplementation*) impl)->calculatePower(healer, patient, applyBattleFatigue);
}

float RangedStimPackAdapter::getRange(CreatureObject* creature) {
	return ((RangedStimPackImplementation*) impl)->getRange(creature);
}

float RangedStimPackAdapter::getEffectiveness() {
	return ((RangedStimPackImplementation*) impl)->getEffectiveness();
}

float RangedStimPackAdapter::getArea() {
	return ((RangedStimPackImplementation*) impl)->getArea();
}

bool RangedStimPackAdapter::isArea() {
	return ((RangedStimPackImplementation*) impl)->isArea();
}

float RangedStimPackAdapter::getRangeMod() {
	return ((RangedStimPackImplementation*) impl)->getRangeMod();
}

bool RangedStimPackAdapter::isRangedStimPack() {
	return ((RangedStimPackImplementation*) impl)->isRangedStimPack();
}

/*
 *	RangedStimPackHelper
 */

RangedStimPackHelper* RangedStimPackHelper::staticInitializer = RangedStimPackHelper::instance();

RangedStimPackHelper::RangedStimPackHelper() {
	className = "RangedStimPack";

	Core::getObjectBroker()->registerClass(className, this);
}

void RangedStimPackHelper::finalizeHelper() {
	RangedStimPackHelper::finalize();
}

DistributedObject* RangedStimPackHelper::instantiateObject() {
	return new RangedStimPack(DummyConstructorParameter::instance());
}

DistributedObjectServant* RangedStimPackHelper::instantiateServant() {
	return new RangedStimPackImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* RangedStimPackHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new RangedStimPackAdapter((RangedStimPackImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

