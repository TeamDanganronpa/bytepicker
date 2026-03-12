#include "positional_writer.hpp"

std::expected<bytepicker::PositionalFileWriter, std::error_code> bytepicker::PositionalFileWriter::open(const std::filesystem::path& file_path) {
	std::ofstream stream(file_path, std::ios::binary);
	if (!stream) return std::unexpected(std::make_error_code(std::errc::bad_file_descriptor));
	return PositionalFileWriter(std::move(stream));
}
