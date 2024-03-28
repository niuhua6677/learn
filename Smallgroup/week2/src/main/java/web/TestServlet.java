package web;

import javax.servlet.*;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;
import java.io.*;
@WebServlet("/test")
public class TestServlet extends HttpServlet {
      //只有空登录密码才是错误的
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        // 处理 GET 请求示例
        String operation = request.getParameter("operation"); // 假设有种情况需要GET参数

        if ("guest_visit".equals(operation)) { // 游客访问按钮对应的操作
            response.sendRedirect("/guest/homepage.html"); // 直接重定向，状态码默认为302 Found
        } else {
            // 返回400 Bad Request，因为请求不符合预期
            response.sendError(HttpServletResponse.SC_BAD_REQUEST, "无效的GET请求");
        }
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        response.setContentType("application/json"); // 设置返回类型为JSON

        String username = request.getParameter("username");
        String password = request.getParameter("password");

        // 模拟检查用户名和密码
        boolean isValid = checkCredentials(username, password); // 假设checkCredentials是验证函数

        if (isValid) {
            // 登录成功，返回200 OK
            PrintWriter out = response.getWriter();
            out.println("{\"status\": \"success\"}");
            response.setStatus(HttpServletResponse.SC_OK);
        } else {
            // 登录失败，返回401 Unauthorized
            response.sendError(HttpServletResponse.SC_UNAUTHORIZED, "用户名或密码错误");
        }
    }

    private boolean checkCredentials(String username, String password) {
        // 这里应该包含实际的验证逻辑，这里仅做模拟，假设所有非空都有效
        return !username.isEmpty() && !password.isEmpty();
    }
}



