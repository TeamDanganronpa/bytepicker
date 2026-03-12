#include "positional_reader.hpp"

std::expected<bytepicker::PositionalFileReader, std::error_code> bytepicker::PositionalFileReader::open(const std::filesystem::path& file_path) {
	if (!std::filesystem::exists(file_path)) return std::unexpected(std::make_error_code(std::errc::no_such_file_or_directory));

	std::ifstream stream(file_path, std::ios::binary);
	if (!stream) return std::unexpected(std::make_error_code(std::errc::bad_file_descriptor));
	return PositionalFileReader(std::move(stream));
}
