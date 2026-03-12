#pragma once

#include <expected>
#include <filesystem>
#include <fstream>
#include <optional>

namespace bytepicker {
	class PositionalFileReader {
		std::ifstream handle_;

		PositionalFileReader(std::ifstream&& handle) : handle_(std::move(handle)) {}

	public:
		~PositionalFileReader() {
			if (this->handle_) this->handle_.close();
		}

		PositionalFileReader& operator=(PositionalFileReader&&) noexcept = default;
		PositionalFileReader(PositionalFileReader&&) noexcept = default;

		static std::expected<PositionalFileReader, std::error_code> open(const std::filesystem::path& file_path);

		[[nodiscard]] std::size_t offset() { return this->handle_.tellg(); }
		void offset(const std::size_t new_offset) { this->handle_.seekg(static_cast<std::streamoff>(new_offset), std::ios_base::beg); }

		template <class BufferT>
		std::optional<std::error_code> read(BufferT* buffer, std::size_t buffer_size = sizeof(BufferT)) {
			if (!this->handle_) return std::make_error_code(std::errc::bad_file_descriptor);
			if (!buffer) return std::make_error_code(std::errc::invalid_argument);
			if (this->handle_.eof()) return std::make_error_code(std::errc::not_enough_memory);

			this->handle_.read(reinterpret_cast<char*>(buffer), static_cast<std::streamoff>(buffer_size));
			if (this->handle_.gcount() != buffer_size || this->handle_.fail() || this->handle_.bad()) return std::make_error_code(std::errc::io_error);
			return std::nullopt;
		}

		template <class BufferT>
		std::optional<std::error_code> read_string(BufferT* buffer, std::size_t buffer_size = sizeof(BufferT)) {
			if (auto result = this->read(buffer, buffer_size); result) return result;
			buffer[buffer_size] = '\0';
			return std::nullopt;
		}
	};
} // namespace bytepicker
