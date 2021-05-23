#pragma once

#include "CesiumMetadata/PropertyView.h"
#include "CesiumUtility/JsonValue.h"
#include <gsl/span>

namespace CesiumMetadata {
class JsonPropertyView : public PropertyView {
public:
  virtual ~JsonPropertyView() noexcept = default;

  virtual JsonPropertyView* asJsonPropertyView() noexcept override {
    return this;
  }

  virtual const JsonPropertyView* asJsonPropertyView() const noexcept override {
    return this;
  }

  virtual gsl::span<const CesiumUtility::JsonValue> asJsons() const = 0;

  virtual gsl::span<CesiumUtility::JsonValue> asJsons() = 0;
};

}