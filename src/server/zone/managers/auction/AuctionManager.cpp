/*
 *	server/zone/managers/auction/AuctionManager.cpp generated by engine3 IDL compiler 0.60
 */

#include "AuctionManager.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/managers/object/ObjectManager.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/managers/auction/AuctionsMap.h"

#include "server/zone/objects/tangible/terminal/vendor/VendorTerminal.h"

#include "server/zone/objects/tangible/terminal/vendor/bazaar/BazaarTerminal.h"

#include "server/zone/objects/auction/AuctionItem.h"

#include "server/zone/objects/scene/SceneObject.h"


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

#include "server/zone/managers/guild/GuildManager.h"

#include "system/util/SortedVector.h"

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

#include "server/zone/objects/auction/Vendor.h"

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

#include "server/zone/managers/name/NameManager.h"

#include "server/zone/managers/holocron/HolocronManager.h"

#include "server/zone/ZoneHandler.h"

#include "engine/service/proto/BaseClientProxy.h"

#include "server/zone/objects/scene/variables/PendingTasksMap.h"

#include "engine/util/u3d/QuadTreeEntry.h"

#include "engine/util/u3d/QuadTree.h"

#include "server/zone/ZoneClientSession.h"

#include "server/zone/managers/object/ObjectManager.h"

#include "system/io/ObjectInputStream.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "server/zone/managers/planet/HeightMap.h"

#include "server/zone/managers/stringid/StringIdManager.h"

#include "server/zone/objects/auction/AuctionItem.h"

#include "engine/service/Message.h"

#include "engine/core/ObjectUpdateToDatabaseTask.h"

#include "server/zone/objects/player/sui/SuiBox.h"

#include "server/zone/managers/auction/AuctionManager.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/managers/planet/PlanetManager.h"

/*
 *	AuctionManagerStub
 */

enum {RPC_INITIALIZE__ = 6,RPC_CHECKVENDORITEMS__,RPC_CHECKAUCTIONS__,RPC_GETITEMATTRIBUTES__PLAYERCREATURE_LONG_,RPC_GETDATA__PLAYERCREATURE_INT_LONG_INT_INT_INT_INT_,RPC_RETRIEVEITEM__PLAYERCREATURE_LONG_LONG_,RPC_BUYITEM__PLAYERCREATURE_LONG_INT_INT_,RPC_DOAUCTIONBID__PLAYERCREATURE_AUCTIONITEM_INT_INT_,RPC_DOINSTANTBUY__PLAYERCREATURE_AUCTIONITEM_INT_INT_,RPC_CHECKBIDAUCTION__PLAYERCREATURE_AUCTIONITEM_INT_INT_,RPC_CANCELITEM__PLAYERCREATURE_LONG_,RPC_GETAUCTIONMAP__};

AuctionManager::AuctionManager(ZoneServer* server) : ManagedService(DummyConstructorParameter::instance()) {
	AuctionManagerImplementation* _implementation = new AuctionManagerImplementation(server);
	ManagedObject::_setImplementation(_implementation);
	_implementation->_setStub(this);
}

AuctionManager::AuctionManager(DummyConstructorParameter* param) : ManagedService(param) {
}

AuctionManager::~AuctionManager() {
}


void AuctionManager::initialize() {
	AuctionManagerImplementation* _implementation = (AuctionManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZE__);

		method.executeWithVoidReturn();
	} else
		_implementation->initialize();
}

void AuctionManager::checkVendorItems() {
	AuctionManagerImplementation* _implementation = (AuctionManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CHECKVENDORITEMS__);

		method.executeWithVoidReturn();
	} else
		_implementation->checkVendorItems();
}

void AuctionManager::checkAuctions() {
	AuctionManagerImplementation* _implementation = (AuctionManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CHECKAUCTIONS__);

		method.executeWithVoidReturn();
	} else
		_implementation->checkAuctions();
}

void AuctionManager::addSaleItem(PlayerCreature* player, unsigned long long objectid, Vendor* vendor, const UnicodeString& description, int price, unsigned int duration, bool auction, bool premium) {
	AuctionManagerImplementation* _implementation = (AuctionManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->addSaleItem(player, objectid, vendor, description, price, duration, auction, premium);
}

AuctionItem* AuctionManager::createVendorItem(PlayerCreature* player, SceneObject* objectToSell, Vendor* vendor, const UnicodeString& description, int price, unsigned int duration, bool auction, bool premium) {
	AuctionManagerImplementation* _implementation = (AuctionManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->createVendorItem(player, objectToSell, vendor, description, price, duration, auction, premium);
}

int AuctionManager::checkSaleItem(PlayerCreature* player, SceneObject* object, Vendor* vendor, int price) {
	AuctionManagerImplementation* _implementation = (AuctionManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->checkSaleItem(player, object, vendor, price);
}

void AuctionManager::getItemAttributes(PlayerCreature* player, unsigned long long objectid) {
	AuctionManagerImplementation* _implementation = (AuctionManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETITEMATTRIBUTES__PLAYERCREATURE_LONG_);
		method.addObjectParameter(player);
		method.addUnsignedLongParameter(objectid);

		method.executeWithVoidReturn();
	} else
		_implementation->getItemAttributes(player, objectid);
}

void AuctionManager::getData(PlayerCreature* player, int extent, unsigned long long vendorObjectID, int screen, unsigned int category, int count, int offset) {
	AuctionManagerImplementation* _implementation = (AuctionManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETDATA__PLAYERCREATURE_INT_LONG_INT_INT_INT_INT_);
		method.addObjectParameter(player);
		method.addSignedIntParameter(extent);
		method.addUnsignedLongParameter(vendorObjectID);
		method.addSignedIntParameter(screen);
		method.addUnsignedIntParameter(category);
		method.addSignedIntParameter(count);
		method.addSignedIntParameter(offset);

		method.executeWithVoidReturn();
	} else
		_implementation->getData(player, extent, vendorObjectID, screen, category, count, offset);
}

void AuctionManager::getLocalVendorData(PlayerCreature* player, Vendor* vendor, int screen, unsigned int category, int count, int offset) {
	AuctionManagerImplementation* _implementation = (AuctionManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->getLocalVendorData(player, vendor, screen, category, count, offset);
}

void AuctionManager::getGalaxyData(PlayerCreature* player, Vendor* vendor, int screen, unsigned int category, int count, int offset) {
	AuctionManagerImplementation* _implementation = (AuctionManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->getGalaxyData(player, vendor, screen, category, count, offset);
}

void AuctionManager::getPlanetData(PlayerCreature* player, Vendor* vendor, int screen, unsigned int category, int count, int offset) {
	AuctionManagerImplementation* _implementation = (AuctionManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->getPlanetData(player, vendor, screen, category, count, offset);
}

void AuctionManager::getRegionData(PlayerCreature* player, Vendor* vendor, int screen, unsigned int category, int count, int offset) {
	AuctionManagerImplementation* _implementation = (AuctionManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->getRegionData(player, vendor, screen, category, count, offset);
}

int AuctionManager::checkRetrieve(PlayerCreature* player, unsigned long long objectIdToRetrieve, Vendor* vendor) {
	AuctionManagerImplementation* _implementation = (AuctionManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->checkRetrieve(player, objectIdToRetrieve, vendor);
}

void AuctionManager::retrieveItem(PlayerCreature* player, unsigned long long objectid, unsigned long long vendorID) {
	AuctionManagerImplementation* _implementation = (AuctionManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_RETRIEVEITEM__PLAYERCREATURE_LONG_LONG_);
		method.addObjectParameter(player);
		method.addUnsignedLongParameter(objectid);
		method.addUnsignedLongParameter(vendorID);

		method.executeWithVoidReturn();
	} else
		_implementation->retrieveItem(player, objectid, vendorID);
}

void AuctionManager::buyItem(PlayerCreature* player, unsigned long long objectid, int price1, int price2) {
	AuctionManagerImplementation* _implementation = (AuctionManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_BUYITEM__PLAYERCREATURE_LONG_INT_INT_);
		method.addObjectParameter(player);
		method.addUnsignedLongParameter(objectid);
		method.addSignedIntParameter(price1);
		method.addSignedIntParameter(price2);

		method.executeWithVoidReturn();
	} else
		_implementation->buyItem(player, objectid, price1, price2);
}

void AuctionManager::doAuctionBid(PlayerCreature* player, AuctionItem* item, int price1, int price2) {
	AuctionManagerImplementation* _implementation = (AuctionManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_DOAUCTIONBID__PLAYERCREATURE_AUCTIONITEM_INT_INT_);
		method.addObjectParameter(player);
		method.addObjectParameter(item);
		method.addSignedIntParameter(price1);
		method.addSignedIntParameter(price2);

		method.executeWithVoidReturn();
	} else
		_implementation->doAuctionBid(player, item, price1, price2);
}

void AuctionManager::doInstantBuy(PlayerCreature* player, AuctionItem* item, int price1, int price2) {
	AuctionManagerImplementation* _implementation = (AuctionManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_DOINSTANTBUY__PLAYERCREATURE_AUCTIONITEM_INT_INT_);
		method.addObjectParameter(player);
		method.addObjectParameter(item);
		method.addSignedIntParameter(price1);
		method.addSignedIntParameter(price2);

		method.executeWithVoidReturn();
	} else
		_implementation->doInstantBuy(player, item, price1, price2);
}

int AuctionManager::checkBidAuction(PlayerCreature* player, AuctionItem* item, int price1, int price2) {
	AuctionManagerImplementation* _implementation = (AuctionManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CHECKBIDAUCTION__PLAYERCREATURE_AUCTIONITEM_INT_INT_);
		method.addObjectParameter(player);
		method.addObjectParameter(item);
		method.addSignedIntParameter(price1);
		method.addSignedIntParameter(price2);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->checkBidAuction(player, item, price1, price2);
}

void AuctionManager::cancelItem(PlayerCreature* player, unsigned long long objectID) {
	AuctionManagerImplementation* _implementation = (AuctionManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CANCELITEM__PLAYERCREATURE_LONG_);
		method.addObjectParameter(player);
		method.addUnsignedLongParameter(objectID);

		method.executeWithVoidReturn();
	} else
		_implementation->cancelItem(player, objectID);
}

AuctionQueryHeadersResponseMessage* AuctionManager::fillAuctionQueryHeadersResponseMessage(PlayerCreature* player, Vendor* vendor, VectorMap<unsigned long long, ManagedReference<AuctionItem* > >* items, int screen, unsigned int category, int count, int offset) {
	AuctionManagerImplementation* _implementation = (AuctionManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->fillAuctionQueryHeadersResponseMessage(player, vendor, items, screen, category, count, offset);
}

AuctionsMap* AuctionManager::getAuctionMap() {
	AuctionManagerImplementation* _implementation = (AuctionManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETAUCTIONMAP__);

		return (AuctionsMap*) method.executeWithObjectReturn();
	} else
		return _implementation->getAuctionMap();
}

DistributedObjectServant* AuctionManager::_getImplementation() {

	_updated = true;
	return dynamic_cast<DistributedObjectServant*>(getForUpdate());}

void AuctionManager::_setImplementation(DistributedObjectServant* servant) {
	setObject(dynamic_cast<AuctionManagerImplementation*>(servant));
}

/*
 *	AuctionManagerImplementation
 */

AuctionManagerImplementation::AuctionManagerImplementation(DummyConstructorParameter* param) : ManagedServiceImplementation(param) {
	_initializeImplementation();
}


AuctionManagerImplementation::~AuctionManagerImplementation() {
}


void AuctionManagerImplementation::finalize() {
}

void AuctionManagerImplementation::_initializeImplementation() {
	_setClassHelper(AuctionManagerHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void AuctionManagerImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (AuctionManager*) stub;
	ManagedServiceImplementation::_setStub(stub);
}

DistributedObjectStub* AuctionManagerImplementation::_getStub() {
	return _this;
}

AuctionManagerImplementation::operator const AuctionManager*() {
	return _this;
}

Object* AuctionManagerImplementation::clone() {
	return dynamic_cast<Object*>(new AuctionManagerImplementation(*this));
}


void AuctionManagerImplementation::lock(bool doLock) {
}

void AuctionManagerImplementation::lock(ManagedObject* obj) {
}

void AuctionManagerImplementation::rlock(bool doLock) {
}

void AuctionManagerImplementation::wlock(bool doLock) {
}

void AuctionManagerImplementation::wlock(ManagedObject* obj) {
}

void AuctionManagerImplementation::unlock(bool doLock) {
}

void AuctionManagerImplementation::runlock(bool doLock) {
}

void AuctionManagerImplementation::_serializationHelperMethod() {
	ManagedServiceImplementation::_serializationHelperMethod();

	_setClassName("AuctionManager");

}

void AuctionManagerImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(AuctionManagerImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool AuctionManagerImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (ManagedServiceImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "auctionMap") {
		TypeInfo<ManagedReference<AuctionsMap* > >::parseFromBinaryStream(&auctionMap, stream);
		return true;
	}

	if (_name == "zoneServer") {
		TypeInfo<ManagedWeakReference<ZoneServer* > >::parseFromBinaryStream(&zoneServer, stream);
		return true;
	}


	return false;
}

void AuctionManagerImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = AuctionManagerImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int AuctionManagerImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "auctionMap";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<ManagedReference<AuctionsMap* > >::toBinaryStream(&auctionMap, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "zoneServer";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<ManagedWeakReference<ZoneServer* > >::toBinaryStream(&zoneServer, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 2 + ManagedServiceImplementation::writeObjectMembers(stream);
}

AuctionManagerImplementation::AuctionManagerImplementation(ZoneServer* server) {
	_initializeImplementation();
	// server/zone/managers/auction/AuctionManager.idl():  		zoneServer = server;
	zoneServer = server;
	// server/zone/managers/auction/AuctionManager.idl():  		Logger.setLoggingName("AuctionManager");
	Logger::setLoggingName("AuctionManager");
	// server/zone/managers/auction/AuctionManager.idl():  		Logger.setLogging(false);
	Logger::setLogging(false);
	// server/zone/managers/auction/AuctionManager.idl():  		Logger.setGlobalLogging(true);
	Logger::setGlobalLogging(true);
}

AuctionsMap* AuctionManagerImplementation::getAuctionMap() {
	// server/zone/managers/auction/AuctionManager.idl():  		return auctionMap;
	return auctionMap;
}

/*
 *	AuctionManagerAdapter
 */

AuctionManagerAdapter::AuctionManagerAdapter(AuctionManagerImplementation* obj) : ManagedServiceAdapter(obj) {
}

Packet* AuctionManagerAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_INITIALIZE__:
		initialize();
		break;
	case RPC_CHECKVENDORITEMS__:
		checkVendorItems();
		break;
	case RPC_CHECKAUCTIONS__:
		checkAuctions();
		break;
	case RPC_GETITEMATTRIBUTES__PLAYERCREATURE_LONG_:
		getItemAttributes((PlayerCreature*) inv->getObjectParameter(), inv->getUnsignedLongParameter());
		break;
	case RPC_GETDATA__PLAYERCREATURE_INT_LONG_INT_INT_INT_INT_:
		getData((PlayerCreature*) inv->getObjectParameter(), inv->getSignedIntParameter(), inv->getUnsignedLongParameter(), inv->getSignedIntParameter(), inv->getUnsignedIntParameter(), inv->getSignedIntParameter(), inv->getSignedIntParameter());
		break;
	case RPC_RETRIEVEITEM__PLAYERCREATURE_LONG_LONG_:
		retrieveItem((PlayerCreature*) inv->getObjectParameter(), inv->getUnsignedLongParameter(), inv->getUnsignedLongParameter());
		break;
	case RPC_BUYITEM__PLAYERCREATURE_LONG_INT_INT_:
		buyItem((PlayerCreature*) inv->getObjectParameter(), inv->getUnsignedLongParameter(), inv->getSignedIntParameter(), inv->getSignedIntParameter());
		break;
	case RPC_DOAUCTIONBID__PLAYERCREATURE_AUCTIONITEM_INT_INT_:
		doAuctionBid((PlayerCreature*) inv->getObjectParameter(), (AuctionItem*) inv->getObjectParameter(), inv->getSignedIntParameter(), inv->getSignedIntParameter());
		break;
	case RPC_DOINSTANTBUY__PLAYERCREATURE_AUCTIONITEM_INT_INT_:
		doInstantBuy((PlayerCreature*) inv->getObjectParameter(), (AuctionItem*) inv->getObjectParameter(), inv->getSignedIntParameter(), inv->getSignedIntParameter());
		break;
	case RPC_CHECKBIDAUCTION__PLAYERCREATURE_AUCTIONITEM_INT_INT_:
		resp->insertSignedInt(checkBidAuction((PlayerCreature*) inv->getObjectParameter(), (AuctionItem*) inv->getObjectParameter(), inv->getSignedIntParameter(), inv->getSignedIntParameter()));
		break;
	case RPC_CANCELITEM__PLAYERCREATURE_LONG_:
		cancelItem((PlayerCreature*) inv->getObjectParameter(), inv->getUnsignedLongParameter());
		break;
	case RPC_GETAUCTIONMAP__:
		resp->insertLong(getAuctionMap()->_getObjectID());
		break;
	default:
		return NULL;
	}

	return resp;
}

void AuctionManagerAdapter::initialize() {
	((AuctionManagerImplementation*) impl)->initialize();
}

void AuctionManagerAdapter::checkVendorItems() {
	((AuctionManagerImplementation*) impl)->checkVendorItems();
}

void AuctionManagerAdapter::checkAuctions() {
	((AuctionManagerImplementation*) impl)->checkAuctions();
}

void AuctionManagerAdapter::getItemAttributes(PlayerCreature* player, unsigned long long objectid) {
	((AuctionManagerImplementation*) impl)->getItemAttributes(player, objectid);
}

void AuctionManagerAdapter::getData(PlayerCreature* player, int extent, unsigned long long vendorObjectID, int screen, unsigned int category, int count, int offset) {
	((AuctionManagerImplementation*) impl)->getData(player, extent, vendorObjectID, screen, category, count, offset);
}

void AuctionManagerAdapter::retrieveItem(PlayerCreature* player, unsigned long long objectid, unsigned long long vendorID) {
	((AuctionManagerImplementation*) impl)->retrieveItem(player, objectid, vendorID);
}

void AuctionManagerAdapter::buyItem(PlayerCreature* player, unsigned long long objectid, int price1, int price2) {
	((AuctionManagerImplementation*) impl)->buyItem(player, objectid, price1, price2);
}

void AuctionManagerAdapter::doAuctionBid(PlayerCreature* player, AuctionItem* item, int price1, int price2) {
	((AuctionManagerImplementation*) impl)->doAuctionBid(player, item, price1, price2);
}

void AuctionManagerAdapter::doInstantBuy(PlayerCreature* player, AuctionItem* item, int price1, int price2) {
	((AuctionManagerImplementation*) impl)->doInstantBuy(player, item, price1, price2);
}

int AuctionManagerAdapter::checkBidAuction(PlayerCreature* player, AuctionItem* item, int price1, int price2) {
	return ((AuctionManagerImplementation*) impl)->checkBidAuction(player, item, price1, price2);
}

void AuctionManagerAdapter::cancelItem(PlayerCreature* player, unsigned long long objectID) {
	((AuctionManagerImplementation*) impl)->cancelItem(player, objectID);
}

AuctionsMap* AuctionManagerAdapter::getAuctionMap() {
	return ((AuctionManagerImplementation*) impl)->getAuctionMap();
}

/*
 *	AuctionManagerHelper
 */

AuctionManagerHelper* AuctionManagerHelper::staticInitializer = AuctionManagerHelper::instance();

AuctionManagerHelper::AuctionManagerHelper() {
	className = "AuctionManager";

	Core::getObjectBroker()->registerClass(className, this);
}

void AuctionManagerHelper::finalizeHelper() {
	AuctionManagerHelper::finalize();
}

DistributedObject* AuctionManagerHelper::instantiateObject() {
	return new AuctionManager(DummyConstructorParameter::instance());
}

DistributedObjectServant* AuctionManagerHelper::instantiateServant() {
	return new AuctionManagerImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* AuctionManagerHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new AuctionManagerAdapter((AuctionManagerImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

