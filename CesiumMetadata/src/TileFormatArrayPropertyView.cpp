#include "..\include\CesiumMetadata\TileFormatArrayPropertyView.h"

namespace CesiumMetadata {
TileFormatArrayPropertyView::TileFormatArrayPropertyView(
    gsl::span<std::byte> bufferView,
    TileFormatType type,
    TileFormatComponentType componentType,
    size_t batchLength)
    : _bufferView{bufferView},
      _type{type},
      _componentType{componentType},
      _batchLength{batchLength} {}

size_t TileFormatArrayPropertyView::numOfInstances() const {
  return _batchLength;
}
} // namespace CesiumMetadata
