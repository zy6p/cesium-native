#pragma once

#include "CesiumMetadata/Metadata.h"
#include "CesiumMetadata/PropertyView.h"
#include <cstddef>
#include <GSL/span>
#include <memory>
#include <map>

namespace CesiumMetadata {
class BatchTableMetadata : public Metadata {
public:
  virtual PropertyView* getProperty(const std::string& propertyName) override;

  virtual const PropertyView*
  getProperty(const std::string& propertyName) const override;

  std::unique_ptr<BatchTableMetadata> create(
      size_t batchLength,
      const gsl::span<const std::byte>& batchTableJsonData,
      const gsl::span<const std::byte>& batchTableBinaryData);

private:
  BatchTableMetadata(
      std::map<std::string, std::unique_ptr<PropertyView>> properties);

  std::map<std::string, std::unique_ptr<PropertyView>> _properties;
};
}