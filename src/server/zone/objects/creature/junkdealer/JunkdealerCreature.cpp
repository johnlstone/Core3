/*
 *	server/zone/objects/creature/junkdealer/JunkdealerCreature.cpp generated by engine3 IDL compiler 0.60
 */

#include "JunkdealerCreature.h"

#include "server/zone/Zone.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/objects/scene/SceneObject.h"


// Imported class dependencies

#include "engine/util/Observer.h"

#include "system/util/Vector.h"

#include "system/io/ObjectOutputStream.h"

#include "engine/util/ObserverEventMap.h"

#include "server/zone/objects/scene/variables/DeltaVector.h"

#include "engine/service/proto/BaseMessage.h"

#include "server/zone/objects/creature/damageovertime/DamageOverTimeList.h"

#include "server/zone/objects/creature/SpeedMultiplierModChanges.h"

#include "server/zone/objects/player/badges/Badges.h"

#include "server/zone/managers/professions/ProfessionManager.h"

#include "server/zone/objects/player/events/PlayerDisconnectEvent.h"

#include "server/zone/objects/area/ActiveArea.h"

#include "server/zone/objects/manufactureschematic/craftingvalues/CraftingValues.h"

#include "server/zone/objects/group/GroupList.h"

#include "server/zone/objects/scene/variables/StringId.h"

#include "engine/core/Task.h"

#include "engine/core/ManagedObject.h"

#include "engine/service/proto/BasePacket.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/objects/player/events/PlayerRecoveryEvent.h"

#include "server/zone/objects/tangible/tool/CraftingTool.h"

#include "server/chat/room/ChatRoom.h"

#include "server/zone/objects/creature/professions/SkillBox.h"

#include "engine/util/u3d/QuadTreeNode.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "server/zone/managers/objectcontroller/ObjectController.h"

#include "server/zone/objects/manufactureschematic/ManufactureSchematic.h"

#include "server/zone/managers/city/CityManager.h"

#include "server/zone/objects/scene/variables/CustomizationVariables.h"

#include "server/zone/managers/creature/CreatureManager.h"

#include "server/zone/objects/creature/variables/CooldownTimerMap.h"

#include "server/login/account/Account.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "system/util/SortedVector.h"

#include "server/zone/objects/player/ValidatedPosition.h"

#include "server/zone/objects/cell/CellObject.h"

#include "system/lang/Time.h"

#include "server/zone/managers/object/ObjectMap.h"

#include "engine/util/Facade.h"

#include "server/zone/objects/guild/GuildObject.h"

#include "server/zone/objects/player/TradeContainer.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/objects/draftschematic/DraftSchematic.h"

#include "system/util/VectorMap.h"

#include "server/login/account/AccountManager.h"

#include "server/zone/objects/creature/variables/CommandQueueAction.h"

#include "server/zone/managers/vendor/VendorManager.h"

#include "server/zone/objects/tangible/tool/SurveyTool.h"

#include "server/zone/ZonePacketHandler.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/objects/scene/variables/DeltaVectorMap.h"

#include "engine/util/Observable.h"

#include "server/zone/managers/planet/MapLocationTable.h"

#include "engine/util/u3d/Quaternion.h"

#include "engine/util/u3d/Coordinate.h"

#include "server/zone/objects/group/GroupObject.h"

#include "server/zone/objects/tangible/weapon/WeaponObject.h"

#include "server/zone/objects/creature/buffs/BuffList.h"

#include "server/zone/objects/creature/variables/SkillBoxList.h"

#include "server/zone/objects/building/BuildingObject.h"

#include "engine/stm/TransactionalReference.h"

#include "server/zone/objects/tangible/sign/SignObject.h"

#include "server/zone/ZoneProcessServer.h"

#include "server/zone/Zone.h"

#include "server/zone/managers/sui/SuiManager.h"

#include "server/zone/objects/intangible/ControlDevice.h"

#include "server/zone/managers/holocron/HolocronManager.h"

#include "server/zone/managers/name/NameManager.h"

#include "engine/service/proto/BaseClientProxy.h"

#include "server/zone/objects/scene/variables/PendingTasksMap.h"

#include "engine/util/u3d/QuadTreeEntry.h"

#include "engine/util/u3d/QuadTree.h"

#include "server/zone/ZoneClientSession.h"

#include "server/zone/objects/creature/buffs/Buff.h"

#include "system/io/ObjectInputStream.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "server/zone/managers/planet/HeightMap.h"

#include "server/zone/objects/manufactureschematic/IngredientSlots.h"

#include "server/chat/StringIdChatParameter.h"

#include "engine/core/ObjectUpdateToDatabaseTask.h"

#include "server/zone/objects/player/sui/SuiBox.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/managers/planet/PlanetManager.h"

/*
 *	JunkdealerCreatureStub
 */

enum {RPC_ACTIVATERECOVERY__,RPC_SENDINITIALMESSAGE__PLAYERCREATURE_,RPC_SENDINITIALCHOICES__PLAYERCREATURE_,RPC_SENDCONVERSATIONSTARTTO__SCENEOBJECT_,RPC_SELECTCONVERSATIONOPTION__INT_SCENEOBJECT_,RPC_GETLOCATION__,RPC_SETLOCATION__STRING_,RPC_ISATTACKABLEBY__CREATUREOBJECT_,RPC_CREATESELLJUNKLOOTSELECTION__PLAYERCREATURE_};

JunkdealerCreature::JunkdealerCreature() : CreatureObject(DummyConstructorParameter::instance()) {
	JunkdealerCreatureImplementation* _implementation = new JunkdealerCreatureImplementation();
	ManagedObject::_setImplementation(_implementation);
	_implementation->_setStub(this);
}

JunkdealerCreature::JunkdealerCreature(DummyConstructorParameter* param) : CreatureObject(param) {
}

JunkdealerCreature::~JunkdealerCreature() {
}


void JunkdealerCreature::loadTemplateData(SharedObjectTemplate* templateData) {
	JunkdealerCreatureImplementation* _implementation = (JunkdealerCreatureImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->loadTemplateData(templateData);
}

void JunkdealerCreature::activateRecovery() {
	JunkdealerCreatureImplementation* _implementation = (JunkdealerCreatureImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ACTIVATERECOVERY__);

		method.executeWithVoidReturn();
	} else
		_implementation->activateRecovery();
}

void JunkdealerCreature::sendInitialMessage(PlayerCreature* player) {
	JunkdealerCreatureImplementation* _implementation = (JunkdealerCreatureImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SENDINITIALMESSAGE__PLAYERCREATURE_);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->sendInitialMessage(player);
}

void JunkdealerCreature::sendInitialChoices(PlayerCreature* player) {
	JunkdealerCreatureImplementation* _implementation = (JunkdealerCreatureImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SENDINITIALCHOICES__PLAYERCREATURE_);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->sendInitialChoices(player);
}

void JunkdealerCreature::sendConversationStartTo(SceneObject* obj) {
	JunkdealerCreatureImplementation* _implementation = (JunkdealerCreatureImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SENDCONVERSATIONSTARTTO__SCENEOBJECT_);
		method.addObjectParameter(obj);

		method.executeWithVoidReturn();
	} else
		_implementation->sendConversationStartTo(obj);
}

void JunkdealerCreature::selectConversationOption(int option, SceneObject* obj) {
	JunkdealerCreatureImplementation* _implementation = (JunkdealerCreatureImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SELECTCONVERSATIONOPTION__INT_SCENEOBJECT_);
		method.addSignedIntParameter(option);
		method.addObjectParameter(obj);

		method.executeWithVoidReturn();
	} else
		_implementation->selectConversationOption(option, obj);
}

String JunkdealerCreature::getLocation() {
	JunkdealerCreatureImplementation* _implementation = (JunkdealerCreatureImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETLOCATION__);

		method.executeWithAsciiReturn(_return_getLocation);
		return _return_getLocation;
	} else
		return _implementation->getLocation();
}

void JunkdealerCreature::setLocation(const String& loc) {
	JunkdealerCreatureImplementation* _implementation = (JunkdealerCreatureImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETLOCATION__STRING_);
		method.addAsciiParameter(loc);

		method.executeWithVoidReturn();
	} else
		_implementation->setLocation(loc);
}

bool JunkdealerCreature::isAttackableBy(CreatureObject* object) {
	JunkdealerCreatureImplementation* _implementation = (JunkdealerCreatureImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISATTACKABLEBY__CREATUREOBJECT_);
		method.addObjectParameter(object);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isAttackableBy(object);
}

void JunkdealerCreature::createSellJunkLootSelection(PlayerCreature* player) {
	JunkdealerCreatureImplementation* _implementation = (JunkdealerCreatureImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CREATESELLJUNKLOOTSELECTION__PLAYERCREATURE_);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->createSellJunkLootSelection(player);
}

DistributedObjectServant* JunkdealerCreature::_getImplementation() {

	_updated = true;
	return dynamic_cast<DistributedObjectServant*>(getForUpdate());}

void JunkdealerCreature::_setImplementation(DistributedObjectServant* servant) {
	setObject(dynamic_cast<JunkdealerCreatureImplementation*>(servant));
}

/*
 *	JunkdealerCreatureImplementation
 */

JunkdealerCreatureImplementation::JunkdealerCreatureImplementation(DummyConstructorParameter* param) : CreatureObjectImplementation(param) {
	_initializeImplementation();
}


JunkdealerCreatureImplementation::~JunkdealerCreatureImplementation() {
}


void JunkdealerCreatureImplementation::finalize() {
}

void JunkdealerCreatureImplementation::_initializeImplementation() {
	_setClassHelper(JunkdealerCreatureHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void JunkdealerCreatureImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (JunkdealerCreature*) stub;
	CreatureObjectImplementation::_setStub(stub);
}

DistributedObjectStub* JunkdealerCreatureImplementation::_getStub() {
	return _this;
}

JunkdealerCreatureImplementation::operator const JunkdealerCreature*() {
	return _this;
}

Object* JunkdealerCreatureImplementation::clone() {
	return dynamic_cast<Object*>(new JunkdealerCreatureImplementation(*this));
}


void JunkdealerCreatureImplementation::lock(bool doLock) {
}

void JunkdealerCreatureImplementation::lock(ManagedObject* obj) {
}

void JunkdealerCreatureImplementation::rlock(bool doLock) {
}

void JunkdealerCreatureImplementation::wlock(bool doLock) {
}

void JunkdealerCreatureImplementation::wlock(ManagedObject* obj) {
}

void JunkdealerCreatureImplementation::unlock(bool doLock) {
}

void JunkdealerCreatureImplementation::runlock(bool doLock) {
}

void JunkdealerCreatureImplementation::_serializationHelperMethod() {
	CreatureObjectImplementation::_serializationHelperMethod();

	_setClassName("JunkdealerCreature");

}

void JunkdealerCreatureImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(JunkdealerCreatureImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool JunkdealerCreatureImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (CreatureObjectImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "location") {
		TypeInfo<String >::parseFromBinaryStream(&location, stream);
		return true;
	}


	return false;
}

void JunkdealerCreatureImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = JunkdealerCreatureImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int JunkdealerCreatureImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "location";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<String >::toBinaryStream(&location, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 1 + CreatureObjectImplementation::writeObjectMembers(stream);
}

JunkdealerCreatureImplementation::JunkdealerCreatureImplementation() {
	_initializeImplementation();
	// server/zone/objects/creature/junkdealer/JunkdealerCreature.idl():  		Logger.setLoggingName("JunkdealerCreature");
	Logger::setLoggingName("JunkdealerCreature");
}

void JunkdealerCreatureImplementation::loadTemplateData(SharedObjectTemplate* templateData) {
	// server/zone/objects/creature/junkdealer/JunkdealerCreature.idl():  		super.loadTemplateData(templateData);
	CreatureObjectImplementation::loadTemplateData(templateData);
	// server/zone/objects/creature/junkdealer/JunkdealerCreature.idl():  		super.optionsBitmask = 0x108;
	CreatureObjectImplementation::optionsBitmask = 0x108;
	// server/zone/objects/creature/junkdealer/JunkdealerCreature.idl():  		super.pvpStatusBitmask = 0;
	CreatureObjectImplementation::pvpStatusBitmask = 0;
}

void JunkdealerCreatureImplementation::activateRecovery() {
}

String JunkdealerCreatureImplementation::getLocation() {
	// server/zone/objects/creature/junkdealer/JunkdealerCreature.idl():  		return location;
	return location;
}

void JunkdealerCreatureImplementation::setLocation(const String& loc) {
	// server/zone/objects/creature/junkdealer/JunkdealerCreature.idl():  		location = loc;
	location = loc;
}

bool JunkdealerCreatureImplementation::isAttackableBy(CreatureObject* object) {
	// server/zone/objects/creature/junkdealer/JunkdealerCreature.idl():  		return false;
	return false;
}

/*
 *	JunkdealerCreatureAdapter
 */

JunkdealerCreatureAdapter::JunkdealerCreatureAdapter(JunkdealerCreatureImplementation* obj) : CreatureObjectAdapter(obj) {
}

Packet* JunkdealerCreatureAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_ACTIVATERECOVERY__:
		activateRecovery();
		break;
	case RPC_SENDINITIALMESSAGE__PLAYERCREATURE_:
		sendInitialMessage((PlayerCreature*) inv->getObjectParameter());
		break;
	case RPC_SENDINITIALCHOICES__PLAYERCREATURE_:
		sendInitialChoices((PlayerCreature*) inv->getObjectParameter());
		break;
	case RPC_SENDCONVERSATIONSTARTTO__SCENEOBJECT_:
		sendConversationStartTo((SceneObject*) inv->getObjectParameter());
		break;
	case RPC_SELECTCONVERSATIONOPTION__INT_SCENEOBJECT_:
		selectConversationOption(inv->getSignedIntParameter(), (SceneObject*) inv->getObjectParameter());
		break;
	case RPC_GETLOCATION__:
		resp->insertAscii(getLocation());
		break;
	case RPC_SETLOCATION__STRING_:
		setLocation(inv->getAsciiParameter(_param0_setLocation__String_));
		break;
	case RPC_ISATTACKABLEBY__CREATUREOBJECT_:
		resp->insertBoolean(isAttackableBy((CreatureObject*) inv->getObjectParameter()));
		break;
	case RPC_CREATESELLJUNKLOOTSELECTION__PLAYERCREATURE_:
		createSellJunkLootSelection((PlayerCreature*) inv->getObjectParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void JunkdealerCreatureAdapter::activateRecovery() {
	((JunkdealerCreatureImplementation*) impl)->activateRecovery();
}

void JunkdealerCreatureAdapter::sendInitialMessage(PlayerCreature* player) {
	((JunkdealerCreatureImplementation*) impl)->sendInitialMessage(player);
}

void JunkdealerCreatureAdapter::sendInitialChoices(PlayerCreature* player) {
	((JunkdealerCreatureImplementation*) impl)->sendInitialChoices(player);
}

void JunkdealerCreatureAdapter::sendConversationStartTo(SceneObject* obj) {
	((JunkdealerCreatureImplementation*) impl)->sendConversationStartTo(obj);
}

void JunkdealerCreatureAdapter::selectConversationOption(int option, SceneObject* obj) {
	((JunkdealerCreatureImplementation*) impl)->selectConversationOption(option, obj);
}

String JunkdealerCreatureAdapter::getLocation() {
	return ((JunkdealerCreatureImplementation*) impl)->getLocation();
}

void JunkdealerCreatureAdapter::setLocation(const String& loc) {
	((JunkdealerCreatureImplementation*) impl)->setLocation(loc);
}

bool JunkdealerCreatureAdapter::isAttackableBy(CreatureObject* object) {
	return ((JunkdealerCreatureImplementation*) impl)->isAttackableBy(object);
}

void JunkdealerCreatureAdapter::createSellJunkLootSelection(PlayerCreature* player) {
	((JunkdealerCreatureImplementation*) impl)->createSellJunkLootSelection(player);
}

/*
 *	JunkdealerCreatureHelper
 */

JunkdealerCreatureHelper* JunkdealerCreatureHelper::staticInitializer = JunkdealerCreatureHelper::instance();

JunkdealerCreatureHelper::JunkdealerCreatureHelper() {
	className = "JunkdealerCreature";

	Core::getObjectBroker()->registerClass(className, this);
}

void JunkdealerCreatureHelper::finalizeHelper() {
	JunkdealerCreatureHelper::finalize();
}

DistributedObject* JunkdealerCreatureHelper::instantiateObject() {
	return new JunkdealerCreature(DummyConstructorParameter::instance());
}

DistributedObjectServant* JunkdealerCreatureHelper::instantiateServant() {
	return new JunkdealerCreatureImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* JunkdealerCreatureHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new JunkdealerCreatureAdapter((JunkdealerCreatureImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

