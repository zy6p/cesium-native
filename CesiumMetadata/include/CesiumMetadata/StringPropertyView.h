#pragma once

#include "CesiumMetadata/PropertyView.h"

namespace CesiumMetadata {
class StringPropertyView : public PropertyView {
public:
  virtual ~StringPropertyView() noexcept = default;

  virtual StringPropertyView* asStringPropertyView() noexcept { return this; }

  virtual const StringPropertyView* asStringPropertyView() const noexcept {
    return this;
  }
};
} // namespace CesiumMetadata