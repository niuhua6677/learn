import utils.jdbc_demo;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner scanner=new Scanner(System.in);
        jdbc_demo jd=new jdbc_demo();
        while(true) {
            jd.showmenu();
            String commond = scanner.next();
            char a = commond.charAt(0);
            switch (a) {
                case '1':
                    jd.insert();
                    break;
                case '2':
                    jd.printall();
                    break;
                case '3':
                    jd.delede();
                    break;
                default:
                    System.out.println("输入有误,请重新输入~");
                    break;
            }
        }
    }
}