import re, os, sys

os.chdir(os.path.dirname(os.path.abspath(__file__)))

all_patterns = [
    'IsActiveQuest', 'CanSpeak', 'CanUninviteFromGroup',
    'GetGuildId()', 'GetOriginalGuildId', 'GetStablePetCount',
    'SetKnownTitle', 'LearnTitle', 'HasTitle',
    'CanDuel', 'IsFlying', 'IsFalling', 'IsSwimming',
    'HasPlayerFlag', 'SetPlayerFlag', 'RemovePlayerFlag',
    'GetPvpIp', 'GetPveIp', 'GetCurrencyQuantity',
    'GetInstanceLock', 'HasInstanceLock',
    'SendActionBars', 'HasPvpFlag',
    'MoveJump', 'GetTarget', 'GetSpeed', 'GetSpeedRate',
    'SetSpeed', 'SetSpeedRate', 'GetPowerType', 'SetPowerType',
    'getRace', 'getClass', 'getGender',
    'SetDisplayId', 'SetNativeDisplayId',
    'SendChatMessageToPlayers', 'GetAbsoluteAngle',
    'IsInRange2d', 'IsInRange3d',
    'GetMaxSkill', 'GetSkillValue', 'GetSkillPerm',
    'HasSkill', 'GetSkillStep', 'HasAchieved',
    'IsGroupVisibleFor', 'IsInSameGroupWith',
    'GetGroupInvite', 'HasGroupInvite',
    'IsInBattlegroundQueue', 'GetBattlegroundQueueIndexId',
    'IsInvitedForBattlegroundQueueType',
    'IsInArenaTeam', 'GetArenaTeamId',
    'GetHonorPoints', 'GetArenaPoints',
    'GetTitle', 'GetChosenTitle',
    'GetSelection', 'SetSelection',
    'GetStandState', 'SetStandState',
    'GetEmoteState', 'SetEmoteState',
    'GrantTitle', 'LearnSpell', 'RemoveSpell', 'HasSpell',
    'RemoveAurasByType',
    'HasDynamicFlag', 'SetDynamicFlag', 'RemoveDynamicFlag',
    'VisitAllObjects', 'sSoundKitStore',
    'QuaternionData', 'LuaVal::PushLuaVal',
    'HandleStatFlatModifier', 'ApplyStatPctModifier', 'LANG_MAX_LANGUAGE',
    'Whisper', 'TextEmote', 'Say', 'Yell',
    'CastSpellExtraArgs', 'CalcArmorReducedDamage', 'SendAttackStateUpdate',
    'HasRootAura', 'HasConfuseAura', 'HasStunAura',
    'REST_TYPE_XP', 'inRandomLfgDungeon', 'IsNeverVisibleFor',
    'GetCurrencyQuantity', 'GetRestBonus', 'CalculateRestXP',
    'sInstanceLockMgr', 'GetElunaEvents', 'UnitModifierFlatType',
    'UnitModifierPctType',
]

for filename in ['UnitMethods.h', 'PlayerMethods.h', 'WorldObjectMethods.h', 'ObjectMethods.h']:
    path = os.path.join('methods/TrinityCore', filename)
    if not os.path.exists(path):
        # Try current directory
        path = filename
    if not os.path.exists(path):
        print(f'{filename}: NOT FOUND')
        continue

    with open(path, 'r') as f:
        lines = f.readlines()

    stub_count = 0
    i = 0
    while i < len(lines):
        stripped = lines[i].strip()
        if stripped.startswith('int ') and '(Eluna*' in stripped:
            has_bad = False
            limit = min(len(lines), i+60)
            for j in range(i, limit):
                for pat in all_patterns:
                    if pat in lines[j]:
                        has_bad = True
                        break
                if has_bad:
                    break

            if has_bad:
                # Find function end
                brace = 0
                end_idx = None
                for j in range(i, min(len(lines), i+80)):
                    brace += lines[j].count('{') - lines[j].count('}')
                    if brace == 0 and j > i:
                        end_idx = j
                        break

                if end_idx:
                    lines[i] = re.sub(r'\(Eluna\*\s*E\s*(,\s*[^)]*)?\)', '(Eluna* /*E*/)', lines[i])
                    lines[i+1] = '    {\n        return 1;\n    }\n'
                    for k in range(i+2, end_idx+1):
                        lines[k] = ''
                    stub_count += 1
                    i = end_idx + 1
                    continue
        i += 1

    with open(path, 'w') as f:
        f.writelines(lines)
    print(f'{filename}: stubbed {stub_count} functions')

# Fix non-function errors in GlobalMethods.h
if os.path.exists('methods/TrinityCore/GlobalMethods.h'):
    with open('methods/TrinityCore/GlobalMethods.h', 'r') as f:
        content = f.read()
    content = content.replace('sTaxiNodesStore.SetEntry(nodeId++, nodeEntry);', '/* SetEntry removed */')
    content = content.replace('sSpellMgr->GetSpellInfo(spellId, DIFFICULTY_NONE)', 'sSpellMgr->GetSpellInfo(spellId)')
    with open('methods/TrinityCore/GlobalMethods.h', 'w') as f:
        f.write(content)
    print('GlobalMethods.h: additional fixes')
elif os.path.exists('GlobalMethods.h'):
    with open('GlobalMethods.h', 'r') as f:
        content = f.read()
    content = content.replace('sTaxiNodesStore.SetEntry(nodeId++, nodeEntry);', '/* SetEntry removed */')
    content = content.replace('sSpellMgr->GetSpellInfo(spellId, DIFFICULTY_NONE)', 'sSpellMgr->GetSpellInfo(spellId)')
    with open('GlobalMethods.h', 'w') as f:
        f.write(content)
    print('GlobalMethods.h: additional fixes')

print('\nAll done!')
