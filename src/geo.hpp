#ifndef PARQUET_FDW_GEO_HPP
#define PARQUET_FDW_GEO_HPP

#include <cstdarg>
#include <cstddef>

#include "arrow/api.h"

#include "parquet/arrow/reader.h"

extern "C"
{
#include "postgres.h"
#include "utils/jsonb.h"
}


#if PG_VERSION_NUM < 140000
#else
#endif

class GeoParquet
{
private:

	std::string m_file_json;

public:

	GeoParquet(const parquet::arrow::FileReader& reader);

	bool read_metadata(const parquet::arrow::FileReader& reader);

	bool is_geo() {
		return ! m_file_json.empty();
	};

	std::string& toString(void) {
		return m_file_json;
	};

};

#endif
