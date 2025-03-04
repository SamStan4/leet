const areAlmostEqual = (s1: string, s2: string): boolean => {
    let i: number = -1,
        j: number = -1;
    for (let k: number = 0; k < s2.length; ++k) {
        if (s1[k] !== s2[k]) {
            if (i === -1)
                i = k;
            else if (j === -1)
                j = k;
            else
                return false;
        }
    }
    return (i === -1 && j === -1) || (i !== -1 && j !== -1 && s1[i] === s2[j] && s1[j] === s2[i]);
};