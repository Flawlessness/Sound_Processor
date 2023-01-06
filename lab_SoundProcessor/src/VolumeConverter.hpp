#pragma once

#include "Processor.hpp"


class VolumeConverter : public Converter
{
public:
    explicit VolumeConverter(unsigned int vol, size_t s = 0, size_t e = 0) : start_pos(s), end_pos(e), volume(vol) {};

    void run_converter(int16_t *, size_t, size_t) override;

private:
    unsigned int volume;
    size_t start_pos;
    size_t end_pos;
};

class VolumeConverterCreator : public ConverterCreator
{
public:
    virtual std::shared_ptr<Converter> create_converter(const std::vector<int> &interval_time, const std::vector<std::string> &input_files, const std::vector<size_t> &indexes_processed_file) const;

    virtual const std::string name() const;

    virtual const std::string help() const;
};

