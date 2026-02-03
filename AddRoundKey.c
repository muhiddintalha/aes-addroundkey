#include <stdio.h>
#include <array>
#include <cctype>

int hexVal(char c) {
    c = (char)std::tolower((unsigned char)c);
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'f') return 10 + (c - 'a');
    return -1;
}

bool hexToBytes16(const std::string& hex, std::array<uint8_t,16>& out) {
    if (hex.size() != 32) return false;
    for (int i = 0; i < 16; i++) {
        int hi = hexVal(hex[2*i]);
        int lo = hexVal(hex[2*i + 1]);
        if (hi < 0 || lo < 0) return false;
        out[i] = (uint8_t)((hi << 4) | lo);
    }
    return true;
}

int main() {
    std::string state_hex = "00112233445566778899aabbccddeeff";
    std::string key_hex   = "000102030405060708090a0b0c0d0e0f";

    std::array<uint8_t,16> state{}, key{}, out{};

    if (!hexToBytes16(state_hex, state) || !hexToBytes16(key_hex, key)) {
        std::cout << "Hex parse hatasi!\n";
        return 1;
    }

    for (int i = 0; i < 16; i++) out[i] = state[i] ^ key[i];

    // Yazdır
    std::ios::fmtflags f(std::cout.flags());
    for (int i = 0; i < 16; i++) {
        std::cout << std::hex << std::nouppercase;
        std::cout.width(2);
        std::cout.fill('0');
        std::cout << (int)out[i];
    }
    std::cout << "\n";
    std::cout.flags(f);

    return 0;
}
