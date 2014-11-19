/**
 * The Forgotten Server - a free and open-source MMORPG server emulator
 * Copyright (C) 2014  Mark Samman <mark.samman@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef FS_ENUMS_H_003445999FEE4A67BCECBE918B0124CE
#define FS_ENUMS_H_003445999FEE4A67BCECBE918B0124CE

enum itemAttrTypes {
	ITEM_ATTRIBUTE_NONE = 0,
	ITEM_ATTRIBUTE_ACTIONID = 1,
	ITEM_ATTRIBUTE_UNIQUEID = 2,
	ITEM_ATTRIBUTE_DESCRIPTION = 4,
	ITEM_ATTRIBUTE_TEXT = 8,
	ITEM_ATTRIBUTE_DATE = 16,
	ITEM_ATTRIBUTE_WRITER = 32,
	ITEM_ATTRIBUTE_NAME = 64,
	ITEM_ATTRIBUTE_ARTICLE = 128,
	ITEM_ATTRIBUTE_PLURALNAME = 256,
	ITEM_ATTRIBUTE_WEIGHT = 512,
	ITEM_ATTRIBUTE_ATTACK = 1024,
	ITEM_ATTRIBUTE_DEFENSE = 2048,
	ITEM_ATTRIBUTE_EXTRADEFENSE = 4096,
	ITEM_ATTRIBUTE_ARMOR = 8192,
	ITEM_ATTRIBUTE_HITCHANCE = 16384,
	ITEM_ATTRIBUTE_SHOOTRANGE = 32768,
	ITEM_ATTRIBUTE_OWNER = 65536,
	ITEM_ATTRIBUTE_DURATION = 131072,
	ITEM_ATTRIBUTE_DECAYSTATE = 262144,
	ITEM_ATTRIBUTE_CORPSEOWNER = 524288,
	ITEM_ATTRIBUTE_CHARGES = 1048576,
	ITEM_ATTRIBUTE_FLUIDTYPE = 2097152,
	ITEM_ATTRIBUTE_DOORID = 4194304
};

enum VipStatus_t : uint8_t {
	VIPSTATUS_OFFLINE = 0,
	VIPSTATUS_ONLINE = 1,
	VIPSTATUS_PENDING = 2
};

enum MarketAction_t {
	MARKETACTION_BUY = 0,
	MARKETACTION_SELL = 1
};

enum MarketRequest_t {
	MARKETREQUEST_OWN_OFFERS = 0xFFFE,
	MARKETREQUEST_OWN_HISTORY = 0xFFFF
};

enum MarketOfferState_t {
	OFFERSTATE_ACTIVE = 0,
	OFFERSTATE_CANCELLED = 1,
	OFFERSTATE_EXPIRED = 2,
	OFFERSTATE_ACCEPTED = 3,

	OFFERSTATE_ACCEPTEDEX = 255
};

enum ChannelEvent_t : uint8_t {
	CHANNELEVENT_JOIN = 0,
	CHANNELEVENT_LEAVE = 1,
	CHANNELEVENT_INVITE = 2,
	CHANNELEVENT_EXCLUDE = 3
};

enum ReportType_t {
	REPORTTYPE_NAME = 0,
	REPORTTYPE_STATEMENT = 1,
	REPORTTYPE_BOT = 2
};

enum CreatureType_t : uint8_t {
	CREATURETYPE_PLAYER = 0,
	CREATURETYPE_MONSTER = 1,
	CREATURETYPE_NPC = 2,
	CREATURETYPE_SUMMON_OWN = 3,
	CREATURETYPE_SUMMON_OTHERS = 4
};

// TODO: Move this to reserved range
enum StorageValues_t {
	STORAGEVALUE_PROMOTION = 30018
};

enum OperatingSystem_t : uint8_t {
	CLIENTOS_LINUX = 0x01,
	CLIENTOS_WINDOWS = 0x02,
	CLIENTOS_FLASH = 0x03,

	CLIENTOS_OTCLIENT_LINUX = 0x0A,
	CLIENTOS_OTCLIENT_WINDOWS = 0x0B,
	CLIENTOS_OTCLIENT_MAC = 0x0C
};

enum SpellGroup_t : uint8_t {
	SPELLGROUP_NONE = 0,
	SPELLGROUP_ATTACK = 1,
	SPELLGROUP_HEALING = 2,
	SPELLGROUP_SUPPORT = 3,
	SPELLGROUP_SPECIAL = 4
};

enum AccountType_t : uint8_t {
	ACCOUNT_TYPE_NORMAL = 1,
	ACCOUNT_TYPE_TUTOR = 2,
	ACCOUNT_TYPE_SENIORTUTOR = 3,
	ACCOUNT_TYPE_GAMEMASTER = 4,
	ACCOUNT_TYPE_GOD = 5
};

enum RaceType_t : uint8_t {
	RACE_NONE	= 0,
	RACE_VENOM 	= 1,
	RACE_BLOOD	= 2,
	RACE_UNDEAD	= 3,
	RACE_FIRE	= 4,
	RACE_ENERGY	= 5
};

enum CombatType_t {
	COMBAT_FIRST = 0,
	COMBAT_NONE = COMBAT_FIRST,
	COMBAT_PHYSICALDAMAGE = 1,
	COMBAT_ENERGYDAMAGE = 2,
	COMBAT_EARTHDAMAGE = 4,
	COMBAT_FIREDAMAGE = 8,
	COMBAT_UNDEFINEDDAMAGE = 16,
	COMBAT_LIFEDRAIN = 32,
	COMBAT_MANADRAIN = 64,
	COMBAT_HEALING = 128,
	COMBAT_DROWNDAMAGE = 256,
	COMBAT_ICEDAMAGE = 512,
	COMBAT_HOLYDAMAGE = 1024,
	COMBAT_DEATHDAMAGE = 2048,
	COMBAT_LAST = COMBAT_DEATHDAMAGE,
	COMBAT_COUNT = 12
};

enum CombatParam_t {
	COMBAT_PARAM_TYPE = 1,
	COMBAT_PARAM_EFFECT = 2,
	COMBAT_PARAM_DISTANCEEFFECT = 3,
	COMBAT_PARAM_BLOCKSHIELD = 4,
	COMBAT_PARAM_BLOCKARMOR = 5,
	COMBAT_PARAM_TARGETCASTERORTOPMOST = 6,
	COMBAT_PARAM_CREATEITEM = 7,
	COMBAT_PARAM_AGGRESSIVE = 8,
	COMBAT_PARAM_DISPEL = 9,
	COMBAT_PARAM_USECHARGES = 10
};

enum CallBackParam_t {
	CALLBACK_PARAM_LEVELMAGICVALUE = 1,
	CALLBACK_PARAM_SKILLVALUE = 2,
	CALLBACK_PARAM_TARGETTILE = 3,
	CALLBACK_PARAM_TARGETCREATURE = 4
};

enum ConditionParam_t {
	CONDITION_PARAM_OWNER = 1,
	CONDITION_PARAM_TICKS = 2,
	//CONDITION_PARAM_OUTFIT = 3,
	CONDITION_PARAM_HEALTHGAIN = 4,
	CONDITION_PARAM_HEALTHTICKS = 5,
	CONDITION_PARAM_MANAGAIN = 6,
	CONDITION_PARAM_MANATICKS = 7,
	CONDITION_PARAM_DELAYED = 8,
	CONDITION_PARAM_SPEED = 9,
	CONDITION_PARAM_LIGHT_LEVEL = 10,
	CONDITION_PARAM_LIGHT_COLOR = 11,
	CONDITION_PARAM_SOULGAIN = 12,
	CONDITION_PARAM_SOULTICKS = 13,
	CONDITION_PARAM_MINVALUE = 14,
	CONDITION_PARAM_MAXVALUE = 15,
	CONDITION_PARAM_STARTVALUE = 16,
	CONDITION_PARAM_TICKINTERVAL = 17,
	CONDITION_PARAM_FORCEUPDATE = 18,
	CONDITION_PARAM_SKILL_MELEE = 19,
	CONDITION_PARAM_SKILL_FIST = 20,
	CONDITION_PARAM_SKILL_CLUB = 21,
	CONDITION_PARAM_SKILL_SWORD = 22,
	CONDITION_PARAM_SKILL_AXE = 23,
	CONDITION_PARAM_SKILL_DISTANCE = 24,
	CONDITION_PARAM_SKILL_SHIELD = 25,
	CONDITION_PARAM_SKILL_FISHING = 26,
	CONDITION_PARAM_STAT_MAXHITPOINTS = 27,
	CONDITION_PARAM_STAT_MAXMANAPOINTS = 28,
	CONDITION_PARAM_STAT_SOULPOINTS = 29,
	CONDITION_PARAM_STAT_MAGICPOINTS = 30,
	CONDITION_PARAM_STAT_MAXHITPOINTSPERCENT = 31,
	CONDITION_PARAM_STAT_MAXMANAPOINTSPERCENT = 32,
	CONDITION_PARAM_STAT_SOULPOINTSPERCENT = 33,
	CONDITION_PARAM_STAT_MAGICPOINTSPERCENT = 34,
	CONDITION_PARAM_PERIODICDAMAGE = 35,
	CONDITION_PARAM_SKILL_MELEEPERCENT = 36,
	CONDITION_PARAM_SKILL_FISTPERCENT = 37,
	CONDITION_PARAM_SKILL_CLUBPERCENT = 38,
	CONDITION_PARAM_SKILL_SWORDPERCENT = 39,
	CONDITION_PARAM_SKILL_AXEPERCENT = 40,
	CONDITION_PARAM_SKILL_DISTANCEPERCENT = 41,
	CONDITION_PARAM_SKILL_SHIELDPERCENT = 42,
	CONDITION_PARAM_SKILL_FISHINGPERCENT = 43,
	CONDITION_PARAM_BUFF_SPELL = 44,
	CONDITION_PARAM_SUBID = 45,
	CONDITION_PARAM_FIELD = 46
};

enum BlockType_t : uint8_t {
	BLOCK_NONE = 0,
	BLOCK_DEFENSE,
	BLOCK_ARMOR,
	BLOCK_IMMUNITY
};

enum skills_t {
	SKILL_FIRST = 0,
	SKILL_FIST = SKILL_FIRST,
	SKILL_CLUB = 1,
	SKILL_SWORD = 2,
	SKILL_AXE = 3,
	SKILL_DISTANCE = 4,
	SKILL_SHIELD = 5,
	SKILL_FISHING = 6,
	SKILL_MAGLEVEL = 7,
	SKILL_LEVEL = 8,
	SKILL_LAST = SKILL_FISHING
};

enum stats_t {
	STAT_FIRST = 0,
	STAT_MAXHITPOINTS = STAT_FIRST,
	STAT_MAXMANAPOINTS,
	STAT_SOULPOINTS,
	STAT_MAGICPOINTS,
	STAT_LAST = STAT_MAGICPOINTS
};

enum formulaType_t {
	COMBAT_FORMULA_UNDEFINED = 0,
	COMBAT_FORMULA_LEVELMAGIC = 1,
	COMBAT_FORMULA_SKILL = 2,
	COMBAT_FORMULA_DAMAGE = 3
};

enum ConditionType_t {
	CONDITION_NONE			= 0,
	CONDITION_POISON		= 1,
	CONDITION_FIRE			= 2,
	CONDITION_ENERGY		= 4,
	CONDITION_BLEEDING		= 8,
	CONDITION_HASTE			= 16,
	CONDITION_PARALYZE		= 32,
	CONDITION_OUTFIT		= 64,
	CONDITION_INVISIBLE		= 128,
	CONDITION_LIGHT			= 256,
	CONDITION_MANASHIELD		= 512,
	CONDITION_INFIGHT		= 1024,
	CONDITION_DRUNK			= 2048,
	CONDITION_EXHAUST_WEAPON = 4096, // unused
	CONDITION_REGENERATION		= 8192,
	CONDITION_SOUL          	= 16384,
	CONDITION_DROWN         	= 32768,
	CONDITION_MUTED         	= 65536,
	CONDITION_CHANNELMUTEDTICKS	= 131072,
	CONDITION_YELLTICKS		= 262144,
	CONDITION_ATTRIBUTES		= 524288,
	CONDITION_FREEZING		= 1048576,
	CONDITION_DAZZLED		= 2097152,
	CONDITION_CURSED		= 4194304,
	CONDITION_EXHAUST_COMBAT	= 8388608, // unused
	CONDITION_EXHAUST_HEAL		= 16777216, // unused
	CONDITION_PACIFIED		= 33554432,
	CONDITION_SPELLCOOLDOWN		= 67108864,
	CONDITION_SPELLGROUPCOOLDOWN	= 134217728
};

enum ConditionId_t : int8_t {
	CONDITIONID_DEFAULT = -1,
	CONDITIONID_COMBAT = 0,
	CONDITIONID_HEAD = 1,
	CONDITIONID_NECKLACE = 2,
	CONDITIONID_BACKPACK = 3,
	CONDITIONID_ARMOR = 4,
	CONDITIONID_RIGHT = 5,
	CONDITIONID_LEFT = 6,
	CONDITIONID_LEGS = 7,
	CONDITIONID_FEET = 8,
	CONDITIONID_RING = 9,
	CONDITIONID_AMMO = 10
};

enum PlayerSex_t : uint8_t {
	PLAYERSEX_FEMALE = 0,
	PLAYERSEX_MALE = 1,
	PLAYERSEX_LAST = PLAYERSEX_MALE
};

enum Vocation_t : uint16_t {
	VOCATION_NONE = 0
};

enum ReturnValue {
	RETURNVALUE_NOERROR = 0,
	RETURNVALUE_NOTPOSSIBLE = 1,
	RETURNVALUE_NOTENOUGHROOM = 2,
	RETURNVALUE_PLAYERISPZLOCKED = 3,
	RETURNVALUE_PLAYERISNOTINVITED = 4,
	RETURNVALUE_CANNOTTHROW = 5,
	RETURNVALUE_THEREISNOWAY = 6,
	RETURNVALUE_DESTINATIONOUTOFREACH = 7,
	RETURNVALUE_CREATUREBLOCK = 8,
	RETURNVALUE_NOTMOVEABLE = 9,
	RETURNVALUE_DROPTWOHANDEDITEM = 10,
	RETURNVALUE_BOTHHANDSNEEDTOBEFREE = 11,
	RETURNVALUE_CANONLYUSEONEWEAPON = 12,
	RETURNVALUE_NEEDEXCHANGE = 13,
	RETURNVALUE_CANNOTBEDRESSED = 14,
	RETURNVALUE_PUTTHISOBJECTINYOURHAND = 15,
	RETURNVALUE_PUTTHISOBJECTINBOTHHANDS = 16,
	RETURNVALUE_TOOFARAWAY = 17,
	RETURNVALUE_FIRSTGODOWNSTAIRS = 18,
	RETURNVALUE_FIRSTGOUPSTAIRS = 19,
	RETURNVALUE_CONTAINERNOTENOUGHROOM = 20,
	RETURNVALUE_NOTENOUGHCAPACITY = 21,
	RETURNVALUE_CANNOTPICKUP = 22,
	RETURNVALUE_THISISIMPOSSIBLE = 23,
	RETURNVALUE_DEPOTISFULL = 24,
	RETURNVALUE_CREATUREDOESNOTEXIST = 25,
	RETURNVALUE_CANNOTUSETHISOBJECT = 26,
	RETURNVALUE_PLAYERWITHTHISNAMEISNOTONLINE = 27,
	RETURNVALUE_NOTREQUIREDLEVELTOUSERUNE = 28,
	RETURNVALUE_YOUAREALREADYTRADING = 29,
	RETURNVALUE_THISPLAYERISALREADYTRADING = 30,
	RETURNVALUE_YOUMAYNOTLOGOUTDURINGAFIGHT = 31,
	RETURNVALUE_DIRECTPLAYERSHOOT = 32,
	RETURNVALUE_NOTENOUGHLEVEL = 33,
	RETURNVALUE_NOTENOUGHMAGICLEVEL = 34,
	RETURNVALUE_NOTENOUGHMANA = 35,
	RETURNVALUE_NOTENOUGHSOUL = 36,
	RETURNVALUE_YOUAREEXHAUSTED = 37,
	RETURNVALUE_PLAYERISNOTREACHABLE = 38,
	RETURNVALUE_CANONLYUSETHISRUNEONCREATURES = 39,
	RETURNVALUE_ACTIONNOTPERMITTEDINPROTECTIONZONE = 40,
	RETURNVALUE_YOUMAYNOTATTACKTHISPLAYER = 41,
	RETURNVALUE_YOUMAYNOTATTACKAPERSONINPROTECTIONZONE = 42,
	RETURNVALUE_YOUMAYNOTATTACKAPERSONWHILEINPROTECTIONZONE = 43,
	RETURNVALUE_YOUMAYNOTATTACKTHISCREATURE = 44,
	RETURNVALUE_YOUCANONLYUSEITONCREATURES = 45,
	RETURNVALUE_CREATUREISNOTREACHABLE = 46,
	RETURNVALUE_TURNSECUREMODETOATTACKUNMARKEDPLAYERS = 47,
	RETURNVALUE_YOUNEEDPREMIUMACCOUNT = 48,
	RETURNVALUE_YOUNEEDTOLEARNTHISSPELL = 49,
	RETURNVALUE_YOURVOCATIONCANNOTUSETHISSPELL = 50,
	RETURNVALUE_YOUNEEDAWEAPONTOUSETHISSPELL = 51,
	RETURNVALUE_PLAYERISPZLOCKEDLEAVEPVPZONE = 52,
	RETURNVALUE_PLAYERISPZLOCKEDENTERPVPZONE = 53,
	RETURNVALUE_ACTIONNOTPERMITTEDINANOPVPZONE = 54,
	RETURNVALUE_YOUCANNOTLOGOUTHERE = 55,
	RETURNVALUE_YOUNEEDAMAGICITEMTOCASTSPELL = 56,
	RETURNVALUE_CANNOTCONJUREITEMHERE = 57,
	RETURNVALUE_YOUNEEDTOSPLITYOURSPEARS = 58,
	RETURNVALUE_NAMEISTOOAMBIGIOUS = 59,
	RETURNVALUE_CANONLYUSEONESHIELD = 60,
	RETURNVALUE_NOPARTYMEMBERSINRANGE = 61,
	RETURNVALUE_YOUARENOTTHEOWNER = 62
};

enum SpeechBubble_t
{
	SPEECHBUBBLE_NONE = 0,
	SPEECHBUBBLE_NORMAL = 1,
	SPEECHBUBBLE_TRADE = 2,
	SPEECHBUBBLE_QUEST = 3,
	SPEECHBUBBLE_QUESTTRADER = 4
};

enum MapMark_t
{
	MAPMARK_TICK = 0,
	MAPMARK_QUESTION = 1,
	MAPMARK_EXCLAMATION = 2,
	MAPMARK_STAR = 3,
	MAPMARK_CROSS = 4,
	MAPMARK_TEMPLE = 5,
	MAPMARK_KISS = 6,
	MAPMARK_SHOVEL = 7,
	MAPMARK_SWORD = 8,
	MAPMARK_FLAG = 9,
	MAPMARK_LOCK = 10,
	MAPMARK_BAG = 11,
	MAPMARK_SKULL = 12,
	MAPMARK_DOLLAR = 13,
	MAPMARK_REDNORTH = 14,
	MAPMARK_REDSOUTH = 15,
	MAPMARK_REDEAST = 16,
	MAPMARK_REDWEST = 17,
	MAPMARK_GREENNORTH = 18,
	MAPMARK_GREENSOUTH = 19
};

struct Outfit_t {
	Outfit_t() {
		lookHead   = 0;
		lookBody   = 0;
		lookLegs   = 0;
		lookFeet   = 0;
		lookType   = 0;
		lookTypeEx = 0;
		lookAddons = 0;
		lookMount  = 0;
	}

	uint16_t lookType;
	uint16_t lookTypeEx;
	uint8_t lookHead;
	uint8_t lookBody;
	uint8_t lookLegs;
	uint8_t lookFeet;
	uint8_t lookAddons;
	uint16_t lookMount;
};

struct LightInfo {
	uint8_t level;
	uint8_t color;
	LightInfo() {
		level = 0;
		color = 0;
	}
	LightInfo(uint8_t _level, uint8_t _color) {
		level = _level;
		color = _color;
	}
};

struct ShopInfo {
	uint32_t itemId;
	int32_t subType;
	uint32_t buyPrice;
	uint32_t sellPrice;
	std::string realName;

	ShopInfo() {
		itemId = 0;
		subType = 1;
		buyPrice = 0;
		sellPrice = 0;
	}

	ShopInfo(uint32_t itemId, int32_t subType = 0, uint32_t buyPrice = 0, uint32_t sellPrice = 0, std::string realName = "")
		: itemId(itemId), subType(subType), buyPrice(buyPrice), sellPrice(sellPrice), realName(realName) {}
};

struct MarketOffer {
	uint32_t price;
	uint32_t timestamp;
	uint16_t amount;
	uint16_t counter;
	uint16_t itemId;
	std::string playerName;
};

struct MarketOfferEx {
	MarketOfferEx() {}
	MarketOfferEx(MarketOfferEx&& other) :
		id(other.id), playerId(other.playerId), timestamp(other.timestamp), price(other.price),
		amount(other.amount), counter(other.counter), itemId(other.itemId), type(other.type),
		playerName(std::move(other.playerName)) {}

	uint32_t id;
	uint32_t playerId;
	uint32_t timestamp;
	uint32_t price;
	uint16_t amount;
	uint16_t counter;
	uint16_t itemId;
	MarketAction_t type;
	std::string playerName;
};

struct ExpiredMarketOffer {
	uint32_t id;
	uint32_t price;
	uint16_t amount;
	uint16_t itemId;
	uint32_t playerId;
};

struct HistoryMarketOffer {
	uint32_t timestamp;
	uint32_t price;
	uint16_t itemId;
	uint16_t amount;
	MarketOfferState_t state;
};

struct MarketStatistics {
	MarketStatistics() {
		numTransactions = 0;
		highestPrice = 0;
		totalPrice = 0;
		lowestPrice = 0;
	}

	uint32_t numTransactions;
	uint32_t highestPrice;
	uint64_t totalPrice;
	uint32_t lowestPrice;
};

struct ModalWindow
{
	std::list<std::pair<std::string, uint8_t>> buttons, choices;
	std::string title, message;
	uint32_t id;
	uint8_t defaultEnterButton, defaultEscapeButton;
	bool priority;

	ModalWindow(uint32_t id, const std::string& title, const std::string& message)
		: title(title), message(message), id(id), defaultEnterButton(0xFF), defaultEscapeButton(0xFF), priority(false) {}
};

enum CombatOrigin
{
	ORIGIN_NONE = 0,
	ORIGIN_CONDITION = 1,
	ORIGIN_SPELL = 2,
	ORIGIN_MELEE = 3,
	ORIGIN_RANGED = 4
};

struct CombatDamage
{
	struct {
		CombatType_t type;
		int32_t value;
	} primary, secondary;

	CombatOrigin origin;
	CombatDamage()
	{
		origin = ORIGIN_NONE;
		primary.type = secondary.type = COMBAT_NONE;
		primary.value = secondary.value = 0;
	}
};

typedef std::list<MarketOffer> MarketOfferList;
typedef std::list<ExpiredMarketOffer> ExpiredMarketOfferList;
typedef std::list<HistoryMarketOffer> HistoryMarketOfferList;
typedef std::list<ShopInfo> ShopInfoList;

#endif
