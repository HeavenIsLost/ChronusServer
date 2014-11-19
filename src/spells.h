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

#ifndef FS_SPELLS_H_D78A7CCB7080406E8CAA6B1D31D3DA71
#define FS_SPELLS_H_D78A7CCB7080406E8CAA6B1D31D3DA71

#include "luascript.h"
#include "player.h"
#include "actions.h"
#include "talkaction.h"
#include "baseevents.h"

class InstantSpell;
class ConjureSpell;
class RuneSpell;
class Spell;

typedef std::map<uint16_t, bool> VocSpellMap;

class Spells final : public BaseEvents
{
	public:
		Spells();
		~Spells();

		Spell* getSpellByName(const std::string& name);
		RuneSpell* getRuneSpell(uint32_t id);
		RuneSpell* getRuneSpellByName(const std::string& name);

		InstantSpell* getInstantSpell(const std::string& words);
		InstantSpell* getInstantSpellByName(const std::string& name);

		uint32_t getInstantSpellCount(const Player* player) const;
		InstantSpell* getInstantSpellByIndex(const Player* player, uint32_t index);

		TalkActionResult_t playerSaySpell(Player* player, std::string& words);

		static Position getCasterPosition(Creature* creature, Direction dir);
		std::string getScriptBaseName() const final;

	protected:
		void clear() final;
		LuaScriptInterface& getScriptInterface() final;
		Event* getEvent(const std::string& nodeName) final;
		bool registerEvent(Event* event, const pugi::xml_node& node) final;

		std::map<uint16_t, RuneSpell*> runes;
		std::map<std::string, InstantSpell*> instants;

		friend class CombatSpell;
		LuaScriptInterface m_scriptInterface;
};

typedef bool (InstantSpellFunction)(const InstantSpell* spell, Creature* creature, const std::string& param);
typedef bool (RuneSpellFunction)(const RuneSpell* spell, Creature* creature, Item* item, const Position& posFrom, const Position& posTo, bool isHotkey);

class BaseSpell
{
	public:
		BaseSpell() {}
		virtual ~BaseSpell() {}

		virtual bool castSpell(Creature* creature) = 0;
		virtual bool castSpell(Creature* creature, Creature* target) = 0;
};

class CombatSpell final : public Event, public BaseSpell
{
	public:
		CombatSpell(Combat* _combat, bool _needTarget, bool _needDirection);
		~CombatSpell();

		bool castSpell(Creature* creature) final;
		bool castSpell(Creature* creature, Creature* target) final;
		bool configureEvent(const pugi::xml_node&) final {
			return true;
		}

		//scripting
		bool executeCastSpell(Creature* creature, const LuaVariant& var);

		bool loadScriptCombat();
		Combat* getCombat() {
			return combat;
		}

	protected:
		std::string getScriptEventName() const final {
			return "onCastSpell";
		}

		Combat* combat;

		bool needDirection;
		bool needTarget;
};

class Spell : public BaseSpell
{
	public:
		Spell();
		~Spell() {}

		bool configureSpell(const pugi::xml_node& node);
		const std::string& getName() const {
			return name;
		}

		void postCastSpell(Player* player, bool finishedSpell = true, bool payCost = true) const;
		void postCastSpell(Player* player, uint32_t manaCost, uint32_t soulCost) const;

		uint32_t getManaCost(const Player* player) const;
		uint32_t getSoulCost() const {
			return soul;
		}
		uint32_t getLevel() const {
			return level;
		}
		uint32_t getMagicLevel() const {
			return magLevel;
		}
		uint32_t getManaPercent() const {
			return manaPercent;
		}
		bool isPremium() const {
			return premium;
		}

		virtual bool isInstant() const = 0;
		bool isLearnable() const {
			return learnable;
		}

		static ReturnValue CreateIllusion(Creature* creature, const Outfit_t& outfit, int32_t time);
		static ReturnValue CreateIllusion(Creature* creature, const std::string& name, int32_t time);
		static ReturnValue CreateIllusion(Creature* creature, uint32_t itemId, int32_t time);

		const VocSpellMap& getVocMap() const {
			return vocSpellMap;
		}

	protected:
		bool playerSpellCheck(Player* player) const;
		bool playerInstantSpellCheck(Player* player, const Position& toPos);
		bool playerRuneSpellCheck(Player* player, const Position& toPos);

		uint8_t spellId;
		SpellGroup_t group;
		uint32_t groupCooldown;
		SpellGroup_t secondaryGroup;
		uint32_t secondaryGroupCooldown;

		uint32_t mana;
		uint32_t manaPercent;
		uint32_t soul;
		uint32_t cooldown;
		uint32_t level;
		uint32_t magLevel;
		int32_t range;

		bool needTarget;
		bool needWeapon;
		bool selfTarget;
		bool blockingSolid;
		bool blockingCreature;
		bool isAggressive;
		bool learnable;
		bool enabled;
		bool premium;

		VocSpellMap vocSpellMap;

	private:
		std::string name;
};

class InstantSpell : public TalkAction, public Spell
{
	public:
		InstantSpell(LuaScriptInterface* _interface);
		~InstantSpell();

		bool configureEvent(const pugi::xml_node& node) override;
		bool loadFunction(const std::string& functionName) override;

		virtual bool playerCastInstant(Player* player, std::string& param);

		bool castSpell(Creature* creature) override;
		bool castSpell(Creature* creature, Creature* target) override;

		//scripting
		bool executeCastSpell(Creature* creature, const LuaVariant& var);

		bool isInstant() const {
			return true;
		}
		bool getHasParam() const {
			return hasParam;
		}
		bool getHasPlayerNameParam() const {
			return hasPlayerNameParam;
		}
		bool canCast(const Player* player) const;
		bool canThrowSpell(const Creature* creature, const Creature* target) const;

	protected:
		std::string getScriptEventName() const override;

		static InstantSpellFunction HouseGuestList;
		static InstantSpellFunction HouseSubOwnerList;
		static InstantSpellFunction HouseDoorList;
		static InstantSpellFunction HouseKick;
		static InstantSpellFunction SearchPlayer;
		static InstantSpellFunction SummonMonster;
		static InstantSpellFunction Levitate;
		static InstantSpellFunction Illusion;

		static House* getHouseFromPos(Creature* creature);

		bool internalCastSpell(Creature* creature, const LuaVariant& var);

		InstantSpellFunction* function;

		bool needDirection;
		bool hasParam;
		bool hasPlayerNameParam;
		bool checkLineOfSight;
		bool casterTargetOrDirection;
};

class ConjureSpell final : public InstantSpell
{
	public:
		ConjureSpell(LuaScriptInterface* _interface);
		~ConjureSpell();

		bool configureEvent(const pugi::xml_node& node) final;
		bool loadFunction(const std::string& functionName) final;

		bool playerCastInstant(Player* player, std::string& param) final;

		bool castSpell(Creature*) final {
			return false;
		}
		bool castSpell(Creature*, Creature*) final {
			return false;
		}

		uint32_t getConjureId() const {
			return conjureId;
		}
		uint32_t getConjureCount() const {
			return conjureCount;
		}
		uint32_t getReagentId() const {
			return conjureReagentId;
		}

	protected:
		std::string getScriptEventName() const final;

		static ReturnValue internalConjureItem(Player* player, uint32_t conjureId, uint32_t conjureCount);

		bool conjureItem(const ConjureSpell* spell, Creature* creature);
		bool internalCastSpell(Creature* creature, const LuaVariant& var);
		Position getCasterPosition(Creature* creature);

		uint32_t conjureId;
		uint32_t conjureCount;
		uint32_t conjureReagentId;
};

class RuneSpell final : public Action, public Spell
{
	public:
		RuneSpell(LuaScriptInterface* _interface);
		~RuneSpell();

		bool configureEvent(const pugi::xml_node& node) final;
		bool loadFunction(const std::string& functionName) final;

		ReturnValue canExecuteAction(const Player* player, const Position& toPos) final;
		bool hasOwnErrorHandler() final {
			return true;
		}

		bool executeUse(Player* player, Item* item, const PositionEx& posFrom,
		                        const PositionEx& posTo, bool extendedUse, uint32_t creatureId, bool isHotkey) final;

		bool castSpell(Creature* creature) final;
		bool castSpell(Creature* creature, Creature* target) final;

		//scripting
		bool executeCastSpell(Creature* creature, const LuaVariant& var, bool isHotkey);

		bool isInstant() const final {
			return false;
		}
		uint16_t getRuneItemId() const {
			return runeId;
		}

	protected:
		std::string getScriptEventName() const final;

		static RuneSpellFunction Illusion;
		static RuneSpellFunction Convince;

		bool internalCastSpell(Creature* creature, const LuaVariant& var, bool isHotkey);

		RuneSpellFunction* function;
		uint16_t runeId;
		bool hasCharges;
};

#endif
