import java.util.HashMap;

class Solution {
    public String intToRoman(int num) {
        String result = "";

        HashMap<Integer, String> m = new HashMap<Integer, String>();

        m.put(1, "I"); m.put(4, "IV"); m.put(5, "V"); m.put(9, "IX");
        m.put(10, "X"); m.put(40, "XL"); m.put(50, "L"); m.put(90, "XC");
        m.put(100, "C"); m.put(400, "CD"); m.put(500, "D"); m.put(900, "CM");
        m.put(1000, "M");

        int cnt = 1;
        while (num != 0) {
            int c = num%10;
            num /= 10;

            String s = m.get(c*cnt);

            if (s != null) {
                result = s.concat(result);
            } else {
                String n_s = "";
                
                if (c >= 5) {
                    n_s += m.get(5*cnt);
                    c -= 5;
                }
                while (c != 0) {
                    n_s += m.get(cnt);
                    c--;
                }

                result = n_s.concat((result));
            }

            cnt *= 10;
        }

        return result;
    }
}

class code1 {
    public static void main(String[] args) {
        Solution s = new Solution();

        System.out.println(s.intToRoman(1994)); // MCMXCIV
        System.out.println(s.intToRoman(3)); // III
        System.out.println(s.intToRoman(58)); // LVIII
    }
}