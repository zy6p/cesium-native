#pragma once

#include "CesiumMetadata/PropertyView.h"
#include <cstdint>
#include <GSL/span>

namespace CesiumMetadata {
class ArrayPropertyView : public PropertyView {
public:
  virtual ~ArrayPropertyView() noexcept = default;

  virtual ArrayPropertyView* asArrayPropertyView() noexcept override {
    return this;
  }

  virtual const ArrayPropertyView*
  asArrayPropertyView() const noexcept override {
    return this;
  }
};
}