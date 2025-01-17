// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "CesiumGltf/ExtensibleObject.h"
#include "CesiumGltf/Library.h"
#include <cstdint>

namespace CesiumGltf {
/**
 * @brief Indices of those attributes that deviate from their initialization
 * value.
 */
struct CESIUMGLTF_API AccessorSparseIndices final : public ExtensibleObject {
  static inline constexpr const char* TypeName = "AccessorSparseIndices";

  /**
   * @brief The indices data type.
   *
   * Valid values correspond to WebGL enums: `5121` (UNSIGNED_BYTE), `5123`
   * (UNSIGNED_SHORT), `5125` (UNSIGNED_INT).
   */
  enum class ComponentType {
    UNSIGNED_BYTE = 5121,

    UNSIGNED_SHORT = 5123,

    UNSIGNED_INT = 5125
  };

  /**
   * @brief The index of the bufferView with sparse indices. Referenced
   * bufferView can't have ARRAY_BUFFER or ELEMENT_ARRAY_BUFFER target.
   */
  int32_t bufferView = -1;

  /**
   * @brief The offset relative to the start of the bufferView in bytes. Must be
   * aligned.
   */
  int64_t byteOffset = 0;

  /**
   * @brief The indices data type.
   *
   * Valid values correspond to WebGL enums: `5121` (UNSIGNED_BYTE), `5123`
   * (UNSIGNED_SHORT), `5125` (UNSIGNED_INT).
   */
  ComponentType componentType = ComponentType();
};
} // namespace CesiumGltf
