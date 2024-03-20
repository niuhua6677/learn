package utils;

import java.util.List;
import java.util.Scanner;

public class jdbc_demo {

    Scanner scanner=new Scanner(System.in);
    basedao b=new basedao();//创建已经封装好的jdbc对象
    public void showmenu(){
        System.out.println("===欢迎进入品牌系统===");
        System.out.println("请选择你要操作的功能:");
        System.out.println("1.添加数据  2.显示数据  3.删除数据");
    }
public void insert() throws Exception {
        String sql="insert into brand values(?,?,?,?,?)";
        Brand brand=new Brand();
    System.out.println("请输入你要插入的数据:(五个数据,用空格分开)");
    brand.setId(Integer.valueOf(scanner.next()));
    brand.setBrandName(scanner.next());
    brand.setCompanyName(scanner.next());
    brand.setDescription(scanner.next());
    brand.setOrdered(Integer.valueOf(scanner.next()));
        int x=b.executeUpdate(sql,brand.getId(),brand.getBrandName(),
                brand.getCompanyName(),brand.getDescription(),brand.getOrdered());
        if(x>0){
            System.out.println("添加成功");
        }else {
            System.out.println("添加失败");
        }
}
public void printall() throws Exception {
        String sql="select * from brand;";
       List<Brand> list= b.executeQuery(Brand.class,sql);
       list.forEach(s-> System.out.println(s));
}
public void delede() throws Exception {
    String sql="delete from brand where brand_name=?";
    Object [] objects={1,1,1,1,1};
    System.out.println("请输入你要删除的品牌名称:");
    String name=scanner.next();
    int x=b.executeUpdate(sql,name);
    if(x>0){
        System.out.println("删除成功");
    }else {
        System.out.println("删除失败");
    }
}
}
