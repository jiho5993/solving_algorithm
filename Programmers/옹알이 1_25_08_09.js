function solution(babbling) {
    var answer = 0;
    
    const s = new Set(["aya", "ye", "woo", "ma"]);
    
    babbling.forEach((b) => {
        let cur = "";
        for (let i=0; i<b.length; i++) {
            cur += b[i];
            if (s.has(cur)) {
                cur = "";
            }
        }
        if (cur == "") answer++;
    });
    
    return answer;
}
