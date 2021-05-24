#pragma once

#include "CesiumMetadata/JsonPropertyView.h"
#include <vector>

namespace CesiumMetadata {
class TileFormatJsonPropertyView : public JsonPropertyView {
public:
  TileFormatJsonPropertyView(std::vector<CesiumUtility::JsonValue> jsons) 
	  : _jsons(std::move(jsons))
  {}

  virtual gsl::span<const CesiumUtility::JsonValue> asJsons() const override {
    return gsl::span<const CesiumUtility::JsonValue>(_jsons.data(), _jsons.size());
  }

  virtual gsl::span<CesiumUtility::JsonValue> asJsons() override {
    return gsl::span<CesiumUtility::JsonValue>(_jsons.data(), _jsons.size());
  }

private:
  std::vector<CesiumUtility::JsonValue> _jsons;
};
}