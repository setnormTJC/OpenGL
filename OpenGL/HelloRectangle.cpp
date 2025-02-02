//
//#include<glad/glad.h>
//#include<glfw3.h>
//
//#include <iostream>
//
//
//
//GLenum glCheckError_(const char* file, int line)
//{
//    GLenum errorCode;
//    while ((errorCode = glGetError()) != GL_NO_ERROR)
//    {
//        std::string error;
//        switch (errorCode)
//        {
//        case GL_INVALID_ENUM:                  error = "INVALID_ENUM"; break;
//        case GL_INVALID_VALUE:                 error = "INVALID_VALUE"; break;
//        case GL_INVALID_OPERATION:             error = "INVALID_OPERATION"; break;
//        case GL_OUT_OF_MEMORY:                 error = "OUT_OF_MEMORY"; break;
//        case GL_INVALID_FRAMEBUFFER_OPERATION: error = "INVALID_FRAMEBUFFER_OPERATION"; break;
//        
//        //default: 
//        //    error = "all good"; 
//        //    break; 
//        }
//        std::cout << error << " | " << file << " (" << line << ")" << std::endl;
//    }
//    return errorCode;
//}
//#define glCheckError() glCheckError_(__FILE__, __LINE__) 
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
//"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//"}\0";
//
//const char* fragmentShaderSource = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//"}\n\0";
//
//
//int main()
//{
//    //std::cout << __FILE__ << std::endl; 
//    //std::cout << __LINE__ << ;
//	glfwInit(); 
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//    //for debugging: 
//    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true); 
//
//	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
//	if (window == NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//    {
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        return -1;
//    }
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
//                                                                //(vector of integers) 
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
//    -0.5f,  0.5f, 0.0f   // top left 
//    };
//
//
//
//    unsigned int indices[] = {  // note that we start from 0!
//        0, 1, 3,   // first triangle
//        1, 2, 3    // second triangle
//    };
//
//
//    unsigned int VAO, VBO, EBO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//    glGenBuffers(1, &EBO);
//
//    glBindVertexArray(VAO);
//
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); 
//
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO); 
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//    
//    //instructing OpenGL how to interpret vertices: 
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//    glBindVertexArray(0); 
//
//    //glCheckError(); 
//
//
//    // render loop
//    // -----------
//    while (!glfwWindowShouldClose(window))
//    {
//        // input
//        // -----
//        processInput(window);
//
//        glClearColor(1.0f, 0.1f, 0.1f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT); 
//
//        glUseProgram(shaderProgram);
//        glBindVertexArray(VAO);
//        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); 
//        glBindVertexArray(0); 
//
//        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
//        // -------------------------------------------------------------------------------
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    glfwTerminate(); 
//
//
//	return 0; 
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