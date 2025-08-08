function solution(strArr) {
    var answer = [];
    
    answer = strArr.map((s, idx) => {
        if (idx % 2 == 0) return s.toLowerCase();
        else return s.toUpperCase();
    });
    
    return answer;
}
