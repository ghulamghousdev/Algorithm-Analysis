function compress(input) {
    if (input === null || input === undefined || input === "") // Handling empty input.
        return "";

    let dic = {};
    let character = w = wc = output = "";
    let enlargeIn = bitsCount = 2;
    let dictSize = 3;
    let val = pos = 0;

    function encode(bitsCount, v, noShift) {
        let m = noShift ? 0xFFFFFFFFFFFF : 1; // dictionary wont go over 48Bits??? 

        for (let i = 0; i < bitsCount; ++i) {
            val = (val << 1) | (v & m);

            if (pos === 15) {
                pos = 0;
                output += String.fromCharCode(val);
                val = 0;
            } else
                pos++;

            if (noShift)
                v = 0;
            else
                v >>= 1;
        }
    }

    for (let i = 0; i < input.length; ++i) {
        character = input.charAt(i);

        if (dic[character] === undefined)
            dic[character] = {
                size: dictSize++,
                create: true
            };
        wc = w + character;

        if (dic[wc] !== undefined)
            w = wc;
        else {
            if (dic[w].create) {
                if (w.charCodeAt(0) < 256) {
                    encode(bitsCount, 0);
                    encode(8, w.charCodeAt(0));
                } else {
                    encode(bitsCount, 1, true)
                    encode(16, w.charCodeAt(0));
                }
                enlargeIn--;

                if (enlargeIn === 0) {
                    enlargeIn = Math.pow(2, bitsCount);
                    bitsCount++;
                }
                dic[w].create = false;
            } else
                encode(bitsCount, dic[w].size);
            enlargeIn--;

            if (enlargeIn === 0) {
                enlargeIn = Math.pow(2, bitsCount);
                bitsCount++;
            }

            if (dic[wc] !== undefined)
                dic[wc].size = dictSize++;
            else
                dic[wc] = {
                    size: dictSize++,
                    create: false
                };
            w = String(character);
        }
    }

    if (w !== "") {
        if (dic[w].create) {
            if (w.charCodeAt(0) < 256) {
                encode(bitsCount, 0);
                encode(8, w.charCodeAt(0));
            } else {
                encode(bitsCount, 1, true)
                encode(16, w.charCodeAt(0));
            }
            enlargeIn--;

            if (enlargeIn === 0) {
                enlargeIn = Math.pow(2, bitsCount);
                bitsCount++;
            }
            dic[w].create = false;
        } else
            encode(bitsCount, dic[w].size);
        enlargeIn--;

        if (enlargeIn === 0) {
            enlargeIn = Math.pow(2, bitsCount);
            bitsCount++;
        }
    }
    encode(bitsCount, 2);

    while (true) {
        val <<= 1;

        if (pos == 15) {
            output += String.fromCharCode(val);
            break;
        } else
            pos++;
    }
    return output;
}

function decompress(input) {
    if (input === null || input === "" || input === undefined) // Handling empty input.
        return "";

    let w;
    let s = [256, 65536];
    let dic = [0, 1, 2];
    let enlargeIn = dicSize = 4;
    let bitsCount = 3;
    let character = entry = result = "";
    let pos = 32768;
    let index = 1;
    let val = input.charCodeAt(0);

    function decode(maxP) {
        let p = 1,
            b = 0;

        while (p != maxP) {
            b |= ((val & pos) > 0 ? 1 : 0) * p;
            p <<= 1;
            pos >>= 1;

            if (pos === 0) {
                pos = 32768;
                val = input.charCodeAt(index++);
            }
        }
        return b;
    }

    let bits = decode(4);

    if (bits === 2)
        return "";
    else if (bits < 2)
        character = String.fromCharCode(decode(s[bits]));
    dic[3] = w = result = character;

    while (true) {
        if (index > input.length)
            return "";
        character = bits = decode(Math.pow(2, bitsCount));

        if (bits === 2)
            return result;
        else if (bits < 2) {
            bits = decode(s[bits]);
            dic[dicSize++] = String.fromCharCode(bits);
            character = dicSize - 1;
            enlargeIn--;
        }

        if (enlargeIn === 0) {
            enlargeIn = Math.pow(2, bitsCount);
            bitsCount++;
        }

        if (dic[character])
            entry = dic[character];
        else {
            if (character === dicSize)
                entry = w + w.charAt(0);
            else
                return "";
        }

        result += entry;
        dic[dicSize++] = w + entry.charAt(0);
        enlargeIn--;
        w = entry;

        if (enlargeIn === 0) {
            enlargeIn = Math.pow(2, bitsCount);
            bitsCount++;
        }
    }
}

module.exports = {
    compress,
    decompress
}