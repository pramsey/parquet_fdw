
#include <string>

#include "geo.hpp"

#include "arrow/result.h"
#include "parquet/arrow/reader.h"


GeoParquet::GeoParquet(const parquet::arrow::FileReader& reader)
{
	read_metadata(reader);
}

bool
GeoParquet::read_metadata(const parquet::arrow::FileReader& reader)
{
    // const std::shared_ptr<const KeyValueMetadata>& key_value_metadata() const;
    auto kv_metadata = reader.parquet_reader()->metadata()->key_value_metadata();
    if (kv_metadata->Contains("geo")) {
        arrow::Result<std::string> r = kv_metadata->Get("geo");
        if (!r.ok())
            throw std::runtime_error("error reading geoparquet metadata");
        m_file_json = r.ValueOrDie();
    }
    return true;
}


