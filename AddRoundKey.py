def add_round_key(state_hex, key_hex):
    state = bytes.fromhex(state_hex)
    key   = bytes.fromhex(key_hex)
    out = bytes(s ^ k for s, k in zip(state, key))
    return out.hex()

state = "00112233445566778899aabbccddeeff"
key   = "000102030405060708090a0b0c0d0e0f"

print(add_round_key(state, key))
# 00102030405060708090a0b0c0d0e0f0
