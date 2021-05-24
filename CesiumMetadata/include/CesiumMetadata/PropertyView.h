#pragma once

namespace CesiumMetadata {
class PrimitivePropertyView;
class ArrayPropertyView;
class DynamicArrayPropertyView;
class JsonPropertyView;
class StringPropertyView;

class PropertyView {
public:
  virtual ~PropertyView() noexcept = default;

  virtual PrimitivePropertyView* asPrimitivePropertyView() noexcept {
    return nullptr;
  }

  virtual const PrimitivePropertyView*
  asPrimitivePropertyView() const noexcept {
    return nullptr;
  }

  virtual ArrayPropertyView* asArrayPropertyView() noexcept { return nullptr; }

  virtual const ArrayPropertyView* asArrayPropertyView() const noexcept {
    return nullptr;
  }

  virtual JsonPropertyView* asJsonPropertyView() noexcept { return nullptr; }

  virtual const JsonPropertyView* asJsonPropertyView() const noexcept {
    return nullptr;
  }

  virtual StringPropertyView* asStringPropertyView() noexcept {
    return nullptr;
  }

  virtual const StringPropertyView* asStringPropertyView() const noexcept {
    return nullptr;
  }
};
} // namespace CesiumMetadata