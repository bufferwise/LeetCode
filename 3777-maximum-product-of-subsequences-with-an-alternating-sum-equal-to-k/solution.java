public class Solution {
    public int maxProduct(int[] a, int k, int l) {
        int I = Integer.MAX_VALUE;
        Map<String, Set<Integer>> d = new HashMap<>();

        for (int xd : a) {
            Map<String, Set<Integer>> nd = new HashMap<>();

            for (Map.Entry<String, Set<Integer>> e : d.entrySet()) {
                nd.put(e.getKey(), new HashSet<>(e.getValue()));
            }

            if (xd == 0) {
                String key = "1#0";
                nd.computeIfAbsent(key, z -> new HashSet<>()).add(0);
            } else {
                if (xd <= l) {
                    String key = "1#" + xd;
                    nd.computeIfAbsent(key, z -> new HashSet<>()).add(xd);
                } else {
                    String key = "1#" + I;
                    nd.computeIfAbsent(key, z -> new HashSet<>()).add(xd);
                }
            }

            for (Map.Entry<String, Set<Integer>> e : d.entrySet()) {
                String[] p = e.getKey().split("#");
                int pr = Integer.parseInt(p[0]);
                int pd = Integer.parseInt(p[1]);
                for (int s : e.getValue()) {
                    int np = 1 - pr;
                    int na = pr == 0 ? s + xd : s - xd;
                    int npd;

                    if (xd == 0) {
                        npd = 0;
                    } else {
                        if (pd == I || (long) pd * xd > l) {
                            npd = I;
                        } else {
                            npd = pd * xd;
                        }
                    }

                    String key = np + "#" + npd;
                    nd.computeIfAbsent(key, z -> new HashSet<>()).add(na);
                }
            }

            d = nd;
        }

        int rs = -1;
        for (Map.Entry<String, Set<Integer>> e : d.entrySet()) {
            String[] p = e.getKey().split("#");
            int pd = Integer.parseInt(p[1]);
            if (pd != I && e.getValue().contains(k)) {
                rs = Math.max(rs, pd);
            }
        }

        return rs;
    }
}
