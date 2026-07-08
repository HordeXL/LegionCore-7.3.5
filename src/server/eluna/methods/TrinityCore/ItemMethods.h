/*
* Copyright (C) 2010 - 2024 Eluna Lua Engine <https://elunaluaengine.github.io/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

#ifndef ITEMMETHODS_H
#define ITEMMETHODS_H

/***
 * Inherits all methods from: [Object]
 */
namespace LuaItem
{
    /**
     * Returns 'true' if the [Item] is soulbound, 'false' otherwise
     *
     * @return bool isSoulBound
     */
    int IsSoulBound(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Item] is account bound, 'false' otherwise
     *
     * @return bool isAccountBound
     */
    int IsBoundAccountWide(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Item] is bound to a [Player] by an enchant, 'false' otehrwise
     *
     * @return bool isBoundByEnchant
     */
    int IsBoundByEnchant(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Item] is not bound to the [Player] specified, 'false' otherwise
     *
     * @param [Player] player : the [Player] object to check the item against
     * @return bool isNotBound
     */
    int IsNotBoundToPlayer(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Item] is locked, 'false' otherwise
     *
     * @return bool isLocked
     */
    int IsLocked(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Item] is a bag, 'false' otherwise
     *
     * @return bool isBag
     */
    int IsBag(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Item] is a currency token, 'false' otherwise
     *
     * @return bool isCurrencyToken
     */
    int IsCurrencyToken(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Item] is a not an empty bag, 'false' otherwise
     *
     * @return bool isNotEmptyBag
     */
    int IsNotEmptyBag(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Item] is broken, 'false' otherwise
     *
     * @return bool isBroken
     */
    int IsBroken(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Item] can be traded, 'false' otherwise
     *
     * @return bool isTradeable
     */
    int CanBeTraded(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Item] is currently in a trade window, 'false' otherwise
     *
     * @return bool isInTrade
     */
    int IsInTrade(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Item] is currently in a bag, 'false' otherwise
     *
     * @return bool isInBag
     */
    int IsInBag(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Item] is currently equipped, 'false' otherwise
     *
     * @return bool isEquipped
     */
    int IsEquipped(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Item] has the [Quest] specified tied to it, 'false' otherwise
     *
     * @param uint32 questId : the [Quest] id to be checked
     * @return bool hasQuest
     */
    int HasQuest(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Item] is a potion, 'false' otherwise
     *
     * @return bool isPotion
     */
    int IsPotion(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Item] is a weapon vellum, 'false' otherwise
     *
     * @return bool isWeaponVellum
     */
    int IsWeaponVellum(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Item] is an armor vellum, 'false' otherwise
     *
     * @return bool isArmorVellum
     */
    int IsArmorVellum(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the [Item] is a conjured consumable, 'false' otherwise
     *
     * @return bool isConjuredConsumable
     */
    int IsConjuredConsumable(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns 'true' if the refund period has expired for this [Item], 'false' otherwise
     *
     * @return bool isRefundExpired
     */
    int IsRefundExpired(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the chat link of the [Item]
     *
     * @table
     * @columns [Locale, ID]
     * @values [LOCALE_enUS, 0]
     * @values [LOCALE_koKR, 1]
     * @values [LOCALE_frFR, 2]
     * @values [LOCALE_deDE, 3]
     * @values [LOCALE_zhCN, 4]
     * @values [LOCALE_zhTW, 5]
     * @values [LOCALE_esES, 6]
     * @values [LOCALE_esMX, 7]
     * @values [LOCALE_ruRU, 8]
     *
     * @param [LocaleConstant] locale = DEFAULT_LOCALE : locale to return the [Item]'s name in
     * @return string itemLink
     */
    int GetItemLink(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns GUID of the [Player] who currently owns the [Item]
     *
     * @return ObjectGuid guid : guid of the [Player] who owns the [Item]
     */
    int GetOwnerGUID(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Player] who currently owns the [Item]
     *
     * @return [Player] player : the [Player] who owns the [Item]
     */
    int GetOwner(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Item]s stack count
     *
     * @return uint32 count
     */
    int GetCount(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Item]s max stack count
     *
     * @return uint32 maxCount
     */
    int GetMaxStackCount(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Item]s current slot
     *
     * @return uint8 slot
     */
    int GetSlot(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Item]s current bag slot
     *
     * @return uint8 bagSlot
     */
    int GetBagSlot(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Item]s enchantment ID by enchant slot specified
     *
     * @param [EnchantmentSlot] enchantSlot : the enchant slot specified
     * @return uint32 enchantId : the id of the enchant slot specified
     */
    int GetEnchantmentId(Eluna* /*E*/)
{
    return 1;
}

#if ELUNA_EXPANSION < EXP_RETAIL
    /**
     * Returns the spell ID tied to the [Item] by spell index
     *
     * @param uint32 spellIndex : the spell index specified
     * @return uint32 spellId : the id of the spell
     */
    int GetSpellId(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the spell trigger tied to the [Item] by spell index
     *
     * @param uint32 spellIndex : the spell index specified
     * @return uint32 spellTrigger : the spell trigger of the specified index
     */
    int GetSpellTrigger(Eluna* /*E*/)
{
    return 1;
}
#endif

    /**
     * Returns class of the [Item]
     *
     * @return uint32 class
     */
    int GetClass(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns subclass of the [Item]
     *
     * @return uint32 subClass
     */
    int GetSubClass(Eluna* /*E*/)
{
    return 1;
}

    /**
    * Returns the ID of the [Item]
    *
    * @return uint32 itemId
    */
    int GetItemId(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the name of the [Item]
     *
     * @return string name
     */
    int GetName(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the display ID of the [Item]
     *
     * @return uint32 displayId
     */
    int GetDisplayId(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the quality of the [Item]
     *
     * @return uint32 quality
     */
    int GetQuality(Eluna* /*E*/)
{
    return 1;
}

    /**
    * Returns the flags of the [Item]
    *
    * @return uint32 flags
    */
    int GetFlags(Eluna* /*E*/)
{
    return 1;
}

    /**
    * Returns the flags2 of the [Item]
    *
    * @return uint32 flags2
    */
    int GetFlags2(Eluna* /*E*/)
{
    return 1;
}

    /**
    * Returns the extraFlags of the [Item]
    *
    * @return uint32 extraFlags
    */
    int GetExtraFlags(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the default purchase count of the [Item]
     *
     * @return uint32 count
     */
    int GetBuyCount(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the purchase price of the [Item]
     *
     * @return uint32 price
     */
    int GetBuyPrice(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the sell price of the [Item]
     *
     * @return uint32 price
     */
    int GetSellPrice(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the inventory type of the [Item]
     *
     * @return uint32 inventoryType
     */
    int GetInventoryType(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Player] classes allowed to use this [Item]
     *
     * @return uint32 allowableClass
     */
    int GetAllowableClass(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Player] races allowed to use this [Item]
     *
     * @return uint32 allowableRace
     */
    int GetAllowableRace(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Item]s level
     *
     * @return uint32 itemLevel
     */
    int GetItemLevel(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the minimum level required to use this [Item]
     *
     * @return uint32 requiredLevel
     */
    int GetRequiredLevel(Eluna* /*E*/)
{
    return 1;
}

#if ELUNA_EXPANSION < EXP_RETAIL
    /**
     * Returns the amount of stat values on this [Item]
     *
     * @return uint32 statsCount
     */
    int GetStatsCount(Eluna* /*E*/)
{
    return 1;
}
#endif

    /**
     * Returns the stat info of the specified stat slot of this [Item]
     *
     * @param uint8 statSlot : the stat slot specified
     * @return int32 statValue
     * @return int32 statType
     */
    int GetStatInfo(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the damage info of the specified damage slot of this [Item]
     *
     * @param uint8 damageSlot : the damage slot specified (1 or 2)
     * @return uint32 damageType
     * @return float minDamage
     * @return float maxDamage
     */
    int GetDamageInfo(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the base attack speed of this [Item]
     *
     * @return uint32 speed
     */
    int GetSpeed(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the base armor of this [Item]
     *
     * @return uint32 armor
     */
    int GetArmor(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the max durability of this [Item]
     *
     * @return uint32 maxDurability
     */
    int GetMaxDurability(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the current durability of this [Item]
     *
     * @return uint32 durabiliy
     */
    int GetDurability(Eluna* /*E*/)
{
    return 1;
}

#if ELUNA_EXPANSION < EXP_RETAIL
    /**
     * Returns the random property ID of this [Item]
     *
     * @return uint32 randomPropertyId
     */
    int GetRandomProperty(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the random suffix ID of this [Item]
     *
     * @return uint32 suffixId
     */
    int GetRandomSuffix(Eluna* /*E*/)
{
    return 1;
}
#endif

    /**
     * Returns the item set ID of this [Item]
     *
     * @return uint32 itemSetId
     */
    int GetItemSet(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the bag size of this [Item], 0 if [Item] is not a bag
     *
     * @return uint32 bagSize
     */
    int GetBagSize(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the [Player] specified as the owner of the [Item]
     *
     * @param [Player] player : the [Player] specified
     */
    int SetOwner(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the binding of the [Item] to 'true' or 'false'
     *
     * @param bool setBinding
     */
    int SetBinding(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the stack count of the [Item]
     *
     * @param uint32 count
     */
    int SetCount(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the specified enchantment of the [Item] to the specified slot
     *
     * @param uint32 enchantId : the ID of the enchant to be applied
     * @param uint32 enchantSlot : the slot for the enchant to be applied to
     * @return bool enchantmentSuccess : if enchantment is successfully set to specified slot, returns 'true', otherwise 'false'
     */
    int SetEnchantment(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Sets the random properties for the [Item] from a given random property ID.
     *
     * @param uint32 randomPropId : The ID of the random property to be applied.
     */
    int SetRandomProperty(Eluna* /*E*/)
{
    return 1;
}

#if ELUNA_EXPANSION < EXP_RETAIL
    /**
     * Sets the random suffix for the [Item] from a given random suffix ID.
     *
     * @param uint32 randomSuffixId : The ID of the random suffix to be applied.
     */
    int SetRandomSuffix(Eluna* /*E*/)
{
    return 1;
}
#endif

    /* OTHER */
    /**
     * Removes an enchant from the [Item] by the specified slot
     *
     * @param uint32 enchantSlot : the slot for the enchant to be removed from
     * @return bool enchantmentRemoved : if enchantment is successfully removed from specified slot, returns 'true', otherwise 'false'
     */
    int ClearEnchantment(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Saves the [Item] to the database
     */
    int SaveToDB(Eluna* /*E*/)
{
    return 1;
}

    ElunaRegister<Item> ItemMethods[] =
    {
        // Getters
        { "GetOwnerGUID", &LuaItem::GetOwnerGUID },
        { "GetOwner", &LuaItem::GetOwner },
        { "GetCount", &LuaItem::GetCount },
        { "GetMaxStackCount", &LuaItem::GetMaxStackCount },
        { "GetSlot", &LuaItem::GetSlot },
        { "GetBagSlot", &LuaItem::GetBagSlot },
        { "GetEnchantmentId", &LuaItem::GetEnchantmentId },
        { "GetItemLink", &LuaItem::GetItemLink },
        { "GetClass", &LuaItem::GetClass },
        { "GetSubClass", &LuaItem::GetSubClass },
        { "GetItemId", &LuaItem::GetItemId },
        { "GetName", &LuaItem::GetName },
        { "GetDisplayId", &LuaItem::GetDisplayId },
        { "GetQuality", &LuaItem::GetQuality },
        { "GetFlags", &LuaItem::GetFlags },
        { "GetFlags2", &LuaItem::GetFlags2 },
        { "GetExtraFlags", &LuaItem::GetExtraFlags },
        { "GetBuyCount", &LuaItem::GetBuyCount },
        { "GetBuyPrice", &LuaItem::GetBuyPrice },
        { "GetSellPrice", &LuaItem::GetSellPrice },
        { "GetInventoryType", &LuaItem::GetInventoryType },
        { "GetAllowableClass", &LuaItem::GetAllowableClass },
        { "GetAllowableRace", &LuaItem::GetAllowableRace },
        { "GetItemLevel", &LuaItem::GetItemLevel },
        { "GetRequiredLevel", &LuaItem::GetRequiredLevel },
        { "GetItemSet", &LuaItem::GetItemSet },
        { "GetBagSize", &LuaItem::GetBagSize },
        { "GetStatInfo", &LuaItem::GetStatInfo },
        { "GetDamageInfo", &LuaItem::GetDamageInfo },
        { "GetSpeed", &LuaItem::GetSpeed },
        { "GetArmor", &LuaItem::GetArmor },
        { "GetMaxDurability", &LuaItem::GetMaxDurability },
        { "GetDurability", &LuaItem::GetDurability },
#if ELUNA_EXPANSION < EXP_RETAIL
        { "GetSpellId", &LuaItem::GetSpellId },
        { "GetSpellTrigger", &LuaItem::GetSpellTrigger },
        { "GetStatsCount", &LuaItem::GetStatsCount },
        { "GetRandomProperty", &LuaItem::GetRandomProperty },
        { "GetRandomSuffix", &LuaItem::GetRandomSuffix },
#else
        { "GetSpellId", METHOD_REG_NONE },
        { "GetSpellTrigger", METHOD_REG_NONE },
        { "GetStatsCount", METHOD_REG_NONE },
        { "GetRandomProperty", METHOD_REG_NONE },
        { "GetRandomSuffix", METHOD_REG_NONE },
#endif

        // Setters
        { "SetOwner", &LuaItem::SetOwner },
        { "SetBinding", &LuaItem::SetBinding },
        { "SetCount", &LuaItem::SetCount },
        { "SetRandomProperty", &LuaItem::SetRandomProperty },
#if ELUNA_EXPANSION < EXP_RETAIL
        { "SetRandomSuffix", &LuaItem::SetRandomSuffix },
#else
        { "SetRandomSuffix", METHOD_REG_NONE },
#endif

        // Boolean
        { "IsSoulBound", &LuaItem::IsSoulBound },
        { "IsBoundAccountWide", &LuaItem::IsBoundAccountWide },
        { "IsBoundByEnchant", &LuaItem::IsBoundByEnchant },
        { "IsNotBoundToPlayer", &LuaItem::IsNotBoundToPlayer },
        { "IsLocked", &LuaItem::IsLocked },
        { "IsBag", &LuaItem::IsBag },
        { "IsCurrencyToken", &LuaItem::IsCurrencyToken },
        { "IsNotEmptyBag", &LuaItem::IsNotEmptyBag },
        { "IsBroken", &LuaItem::IsBroken },
        { "CanBeTraded", &LuaItem::CanBeTraded },
        { "IsInTrade", &LuaItem::IsInTrade },
        { "IsInBag", &LuaItem::IsInBag },
        { "IsEquipped", &LuaItem::IsEquipped },
        { "HasQuest", &LuaItem::HasQuest },
        { "IsPotion", &LuaItem::IsPotion },
        { "IsWeaponVellum", &LuaItem::IsWeaponVellum },
        { "IsArmorVellum", &LuaItem::IsArmorVellum },
        { "IsRefundExpired", &LuaItem::IsRefundExpired },
        { "IsConjuredConsumable", &LuaItem::IsConjuredConsumable },
        { "SetEnchantment", &LuaItem::SetEnchantment },
        { "ClearEnchantment", &LuaItem::ClearEnchantment },

        // Other
        { "SaveToDB", &LuaItem::SaveToDB }
    };
};
#endif
