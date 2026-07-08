import os, re

all_patterns = [
    'GetNpcFlags', 'GetCreatureClassification', 'GetLootMode', 'GetSpawnId', 'SetNpcFlag',
    'SetLootMode', 'GetMembers', 'IsTrigger', 'CanStartAttack', 'HasLootMode',
    'GetWanderDistance', 'GetWaypointPathId', 'GetCurrentWaypointInfo', 'GetAggroRange',
    'GetThreatManager', 'ItemContext', 'IsInFlight', 'FinishTaxiFlight',
    'GossipOptionNpc', 'GossipOptionFlags', 'PET_SAVE_AS_CURRENT', 'PetSaveMode',
    'IsProcDisabled', 'GetProcCooldown', 'AttributesEx',
    'VisitAllObjects', 'GetAbsoluteAngle',
    'HasDynamicFlag', 'SetDynamicFlag', 'RemoveDynamicFlag',
    'CastSpellExtraArgs', 'SendAttackStateUpdate', 'CalcArmorReducedDamage',
    'MoveJump', 'HandleStatFlatModifier', 'ApplyStatPctModifier',
    'UnitModifierFlatType', 'UnitModifierPctType', 'LANG_MAX_LANGUAGE',
    'SetEmoteState', 'GetPowerType', 'SetPowerType',
    'SetPvpFlag', 'RemovePvpFlag',
    'REST_TYPE_XP', 'inRandomLfgDungeon', 'IsNeverVisibleFor',
    'GetCurrencyQuantity', 'sInstanceLockMgr',
    'CurrencyGainSource', 'QUEST_OBJECTIVE_PROGRESS_BAR',
    'UpdateQuestObjectiveProgress', 'CONFIG_QUEST_ENABLE_QUEST_TRACKER',
    'CharacterDatabasePreparedStatement', 'CHAR_UPD_QUEST_TRACK_GM_COMPLETE',
    'SendAuctionHello', 'PlayerInteractionType', 'ResetAchievements',
    'CanTitanGrip', 'CanSpeak', 'CanUninviteFromGroup',
    'GetArenaTeamId', 'SummonPet(', 'GetQuestTemplate', 'GetGuildId(',
    'IsAlive(', 'IsBanker', 'IsCharmed', 'IsServiceProvider',
    'IsSpiritService', 'IsGossip', 'IsTaxi',
    'CanDuel', 'IsFlying', 'IsFalling', 'IsSwimming',
    'HasPlayerFlag', 'SetPlayerFlag', 'RemovePlayerFlag',
    'GetSelection', 'SetSelection', 'GetStandState', 'SetStandState',
    'GetEmoteState', 'SetEmoteState',
    'GetMovementFlags', 'SetMovementFlags',
    'RemoveAurasByType', 'IsGameMaster',
    'sSoundKitStore', 'sAccountMgr',
    'LuaVal::PushLuaVal', 'QuaternionData',
    'HasSpell(', 'LearnSpell', 'RemoveSpell',
    'LearnTalent', 'ResetTalents', 'GrantTitle',
    'SendChatMessageToPlayers',
    'GetChatFlags', 'GetXP', 'DurabilityRepair',
    'Whisper', 'TextEmote', 'Say', 'Yell',
    'IsAuctioneer', 'IsGuildMaster', 'IsBattleMaster', 'IsInnkeeper',
    'IsTrainer', 'IsArmorer', 'IsBirdMaster', 'IsSpiritGuide',
    'IsSpiritHealer', 'IsTabardDesigner', 'IsVendor', 'IsRepairer',
    'IsQuestGiver', 'GetMountDisplayId', 'GetCharmedGUID',
    'm_activePlayerData', 'GetVictim', 'GetGender', 'GetRace', 'GetClass',
    'IsInCombat', 'GetPassenger', 'GetPassengers',
    'Milliseconds', 'GetWinner', 'GetStartTime', 'GetBracketId',
    'GetMaxLevel', 'GetMinLevel',
]

method_dir = 'F:/Github/LegionCore-7.3.5/src/server/eluna/methods/TrinityCore'
for filename in sorted(os.listdir(method_dir)):
    if not filename.endswith('Methods.h'):
        continue
    path = os.path.join(method_dir, filename)
    with open(path, 'r') as f:
        lines = f.readlines()

    stub_count = 0
    i = 0
    while i < len(lines):
        stripped = lines[i].strip()
        if stripped.startswith('int ') and '(Eluna*' in stripped:
            has_bad = False
            for j in range(i, min(len(lines), i+200)):
                for pat in all_patterns:
                    if pat in lines[j]:
                        has_bad = True
                        break
                if has_bad:
                    break

            if has_bad:
                brace = 0
                end_idx = None
                for j in range(i, min(len(lines), i+200)):
                    brace += lines[j].count('{') - lines[j].count('}')
                    if brace == 0 and j > i:
                        end_idx = j
                        break

                if end_idx:
                    lines[i] = lines[i].split('(Eluna*')[0] + '(Eluna* /*E*/)\n'
                    lines[i+1] = '{\n    return 1;\n}\n'
                    for k in range(i+2, end_idx+1):
                        lines[k] = ''
                    stub_count += 1
                    i = end_idx
        i += 1

    with open(path, 'w') as f:
        f.writelines(lines)
    if stub_count > 0:
        print(f'{filename}: stubbed {stub_count}')

print('ALL DONE')
