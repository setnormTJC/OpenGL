//Uses a UNIFORM -> similar to global variable in GLSL 
// 
// 
// 
// 

//#include<glad/glad.h>
//#include<glfw3.h>
//
//#include <iostream>
//
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow* window);
//
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
//const char* vertexShaderSource = "#version 330 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"void main()\n"
//"{\n"
//"   gl_Position = vec4(aPos, 1.0);\n"
//"}\0";
//
//const char* fragmentShaderSource = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"uniform vec4 ourColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = ourColor;\n"
//"}\n\0";
//
//
//int main()
//{
//
//
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//    //for debugging: 
//    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);
//
//    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
//    if (window == NULL)
//    {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//    glfwMakeContextCurrent(window);
//
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//    {
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        return -1;
//    }
//
//    //int nrAttributes;
//    //glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
//    //std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;
//
//    unsigned int vertexShader;
//    vertexShader = glCreateShader(GL_VERTEX_SHADER);
//
//    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//    glCompileShader(vertexShader);
//
//    int  success;
//    char infoLog[512];
//    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success); //iv -> int vector 
//    //(vector of integers) 
//    if (!success)
//    {
//        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//
//    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//    glCompileShader(fragmentShader);
//
//    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//
//    if (!success)
//    {
//        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//        std::cout << "Frag shader compilation failed - " << infoLog << std::endl;
//    }
//
//    unsigned int shaderProgram = glCreateProgram();
//    glAttachShader(shaderProgram, vertexShader);
//    glAttachShader(shaderProgram, fragmentShader);
//    glLinkProgram(shaderProgram);
//
//    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//
//    if (!success)
//    {
//        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//        std::cout << "linking shader program failed ... " << infoLog << std::endl;
//    }
//
//    glDeleteShader(vertexShader);
//    glDeleteShader(fragmentShader);
//
//
//    float vertices[] = {
//     0.5f,  0.5f, 0.0f,  // top right
//     0.5f, -0.5f, 0.0f,  // bottom right
//    -0.5f, -0.5f, 0.0f,  // bottom left
//
//    //second triangle:
//    -0.5f, 0.5f, 0.0f, 
//    -1.0f, 0.0f, 0.0f, 
//    -1.0f, 1.0f, 0.0f
//    };
//
//    unsigned int VAO, VBO; 
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//
//    glBindVertexArray(VAO);
//
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//    //instructing OpenGL how to interpret vertices: 
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//    //glVertexAttribPointer( //
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//    //glBindBuffer()
//    glBindVertexArray(0);
//
//    //glCheckError(); 
//
//
//    // render loop
//    // -----------
//
//    int frameNumber = 0; 
//
//    while (!glfwWindowShouldClose(window))
//    {
//        // input
//        // -----
//        processInput(window);
//
//        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
//
//
//        float timeValue = glfwGetTime();//time since glfwInit!
//
//        //std::cout << timeValue << std::endl;
//        //default output every frame is about 0.1 ms (a TENTH of a millisecond) 
//        //(may be limited by precision output of cout) 
//
//        float greenValue = (sin(timeValue))*(sin(timeValue)); //periodic - maintains limit between -1 and 1
//
//        int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor"); 
//        //glGetUniformLocation()
//        if (vertexColorLocation == -1)
//        {
//            std::cout << "could not find uniform\n"; 
//        }
//
//        glUseProgram(shaderProgram);
//
//        glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f); 
//
//        glBindVertexArray(VAO);
//        
//
//
//        glDrawArrays(GL_TRIANGLES, 0, 6);
//        //glDrawArrays()
//        //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//        glBindVertexArray(0);
//
//        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
//        // -------------------------------------------------------------------------------
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//
//
//        //std::cout << "Frame number: " << frameNumber << "\tTime since init: " << timeValue << "\n";
//        //frameNumber++; 
//
//    }
//
//    glfwTerminate();
//
//
//    return 0;
//}
//
//void processInput(GLFWwindow* window)
//{
//    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, true);
//}
//
//// glfw: whenever the window size changed (by OS or user resize) this callback function executes
//// ---------------------------------------------------------------------------------------------
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//    // make sure the viewport matches the new window dimensions; note that width and 
//    // height will be significantly larger than specified on retina displays.
//    glViewport(0, 0, width, height);
//}