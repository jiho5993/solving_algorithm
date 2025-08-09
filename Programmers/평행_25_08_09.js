function solution(dots) {
    var answer = 0;
    
    for (let i=0; i<4; i++) {
        for (let j=0; j<4; j++) {
            const a = Math.abs(dots[i][0]-dots[j][0]) / Math.abs(dots[i][1]-dots[j][1]);
            const d = [];
            for (let k=0; k<4; k++) {
                if (k === i || k === j) continue;
                d.push(k);
            }
            const b = Math.abs(dots[d[0]][0]-dots[d[1]][0]) / Math.abs(dots[d[0]][1]-dots[d[1]][1]);
            
            if (a == b) return 1;
        }
    }
    
    return answer;
}
