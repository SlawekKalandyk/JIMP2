//
// Created by kalaslaw on 27.03.18.
//

#ifndef JIMP_EXERCISES_MEMORYCHUNK_H
#define JIMP_EXERCISES_MEMORYCHUNK_H

#include <cstdint>
#include <algorithm>

namespace memorychunk {
    class  Memorychunk {
    public:
        MemoryChunk(size_sz);

        int8_t *MemoryAt(size_t offset) const;

        size_t ChunkSize() const;
    private:

    };
}

#endif //JIMP_EXERCISES_MEMORYCHUNK_H
