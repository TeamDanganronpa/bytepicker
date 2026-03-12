#pragma once

#include <expected>
#include <filesystem>
#include <fstream>
#include <optional>

namespace bytepicker {
	class PositionalFileWriter {
		std::ofstream handle_;

		PositionalFileWriter(std::ofstream&& handle) : handle_(std::move(handle)) {}

	public:
		~PositionalFileWriter() {
			if (this->handle_) {
				this->handle_.flush();
				this->handle_.close();
			}
		}

		PositionalFileWriter& operator=(PositionalFileWriter&&) noexcept = default;
		PositionalFileWriter(PositionalFileWriter&&) noexcept = default;

		static std::expected<PositionalFileWriter, std::error_code> open(const std::filesystem::path& file_path);

		[[nodiscard]] std::size_t offset() { return this->handle_.tellp(); }
		void offset(const std::size_t new_offset) { this->handle_.seekp(static_cast<std::streamoff>(new_offset), std::ios_base::beg); }

		template <class ValueT>
		std::optional<std::error_code> write(ValueT* value, std::size_t value_size = sizeof(ValueT)) {
			if (!this->handle_) return std::make_error_code(std::errc::bad_file_descriptor);
			if (!value) return std::make_error_code(std::errc::invalid_argument);
			this->handle_.write(reinterpret_cast<char*>(value), static_cast<std::streamoff>(value_size));
			if (this->handle_.fail() || this->handle_.bad()) return std::make_error_code(std::errc::io_error);
			return std::nullopt;
		}
	};
} // namespace bytepicker
