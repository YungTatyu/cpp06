#include "Serializer.hpp"
#include "Data.hpp"

/**
 * @brief データをシリアル化する
 *
 * 構造体は異なるデータ型を含むので、バイト列（同じデータの型のバイトの連続）を表現する
 *
 * uintptr_t: Integer type capable of holding a value converted from a void pointer
 * and then be converted back to that type with a value that compares equal to the original pointer.
 *
 * ポインタサイズの符号なし整数型
 * この型は、以下の動作が保証される：
 * 有効なvoidへのポインタからuintptr_t型への変換
 * uintptr_t型のポインタ値からvoidへのポインタへの逆変換
 * 変換前と逆変換のポインタ値が等値となる
 *
 * reinterpret_cast:
 * 異なる型同士のキャストで使用
 * ポインタ型同士の変換
 * int型からポインタ型への変換
 *
 * @param ptr
 * @return uintptr_t
 */
uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t	serialize = reinterpret_cast<uintptr_t>(ptr);

	// std::memcpy(reinterpret_cast<void *>(&serialize), reinterpret_cast<void *>(ptr), sizeof(Data));
	return serialize;
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	Data	*newData = reinterpret_cast<Data *>(raw);

	// *newData = *reinterpret_cast<Data *>(&raw);
	// std::memcpy(static_cast<void *>(newData), static_cast<void *>(&raw), sizeof(Data));
	return newData;
}
