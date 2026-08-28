let sz: number;
let freq: Uint16Array;
const aCode = 'a'.charCodeAt(0);
let oddChar: string;
let semLen: number;
let str: string;
let tar: string;

const func = (preSame: boolean): boolean => {
    const ind = str.length;

    if (ind === semLen) {
        const res = str + oddChar + str.split('').reverse().join('');

        if (res > tar) {
            str = res;

            return true;
        }

        return false;
    }
    const tarIndCode = tar.charCodeAt(ind)-aCode;

    for (
        let i: number = preSame ? tarIndCode : 0;
        i < 26;
        ++i
    ) {
        if (freq[i] === 0) {
            continue;
        }
        const ch = String.fromCharCode(aCode + i);
        str += ch;
        --freq[i];

        if (func(preSame && (i === tarIndCode))) {
            return true;
        }
        ++freq[i];
        str = str.slice(0, str.length - 1);
    }

    return false;
};

function lexPalindromicPermutation(txt: string, _Tar: string): string {
    sz = txt.length;
    semLen = sz >> 1;
    freq = new Uint16Array(26);
    str = oddChar = "";
    tar = _Tar;

    for (const ch of txt) {
        ++freq[ch.charCodeAt(0) - aCode];
    }

    for (let i: number = 0; i < 26; ++i) {
        if (freq[i] & 1) {
            if (oddChar === "") {
                oddChar = String.fromCharCode(i + aCode);
            } else {
                return "";
            }
        }
        freq[i] >>= 1
    }
    func(true);

    return str;
};