#pragma once

#include "CEntity.h"
#include "CBlockPos.h"
#include <stdint.h>

class C_GameMode {
public:
	void attack(C_Entity* entity) {
		using attack = void(__fastcall*)(void*, void*);
		static attack attackFunc = reinterpret_cast<attack>(Utils::FindSignature("48 8B C4 55 48 8D 68 ?? 48 81 EC ?? ?? ?? ?? 48 C7 45 ?? FE FF FF FF 48 89 58 ?? 48 89 70 ?? 48 89 78 ?? 48 8B 05 ?? ?? ?? ?? 48 33 C4 48 89 45 ?? 48 8B FA 48 8B F1 48 C7 45 ?? 00 00 00 00 B9 ?? ?? ?? ?? E8 ?? ?? ?? ?? 48 8B D8 48 89 45 ?? 33 D2 41 B8 ?? ?? ?? ?? 48 8B C8 E8 ?? ?? ?? ?? 48 8B CB E8 ?? ?? ?? ?? 90 48 89 45 ?? C6"));

		if (attackFunc != 0x0)
			attackFunc(this,  entity);
	}

	void destroyBlock(C_BlockPos* block, uint8_t blockSide) {
		using destroyBlock = void(__fastcall*)(void*, C_BlockPos*, int);
		static destroyBlock destroyBlockFunc = reinterpret_cast<destroyBlock>(Utils::FindSignature("55 57 41 56 48 8D 68 ?? 48 81 EC ?? ?? ?? ?? 48 C7 45 ?? FE FF FF FF 48 89 58 ?? 48 89 70 ?? 48 8B 05 ?? ?? ?? ?? 48 33 C4 48 89 45 ?? 45 0F B6 F0") - 3);

		if (destroyBlockFunc != 0x0) {
			// 
			destroyBlockFunc(this, block, blockSide);
		}
			
	}

	void _creativeDestroyBlock(C_BlockPos* block, uint8_t blockSide) {
		// 

		using _creativeDestroyBlock = void(__fastcall*)(void*, const void*, uint8_t face);
		static _creativeDestroyBlock destroyBlockFunc = reinterpret_cast<_creativeDestroyBlock>(Utils::FindSignature("56 57 48 81 EC 80 00 00 00 48 C7 44 24 20 FE FF FF FF 48 8B 05 5D 24 13 01 48 33 C4") - 2);

		if (destroyBlockFunc != 0x0) {
			// 
			destroyBlockFunc(this, block, blockSide);
		}

	}

	void _destroyBlockInternal(C_BlockPos* block, uint8_t blockSide) {

		using destroyBlockInternal = void(__fastcall*)(void*, C_BlockPos*, uint8_t face);
		static destroyBlockInternal destroyBlockFunc = reinterpret_cast<destroyBlockInternal>(Utils::FindSignature("40 55 56 57 41 54 41 55 41 56 41 57 48 8D 6C 24 D9 48 81 EC E0 00 00 00 48 C7 45 87 FE FF FF FF 48 89 9C 24 30 01 00 00"));
		if (destroyBlockFunc != 0x0) {
			// 
			destroyBlockFunc(this, block, blockSide);
		}

	}
};