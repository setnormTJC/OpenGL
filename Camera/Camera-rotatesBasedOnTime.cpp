//
//#include<glad/glad.h>
//#include<glfw3.h>
//
//#include <iostream>
//
//#include"Shader.h"
//
//#include<glm/glm/glm.hpp>
//#include <glm/glm/gtc/matrix_transform.hpp>
//#include <glm/glm/gtc/type_ptr.hpp>
//
//
//#define STB_IMAGE_IMPLEMENTATION
////#include"C:/Users/snorm/Downloads/stb_image.h"
//
//#include"stb_image.h"
//#include <vector>
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow* window);
//
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
//
//int main()
//{
//
//
//#pragma region intiializing OpenGL
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
//
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
//
//#pragma endregion opens window, does glad stuff
//
//    //a constructor that does MANY things - hides a few of OpenGL's boilerplate functions
//    Shader ourShader("../myResources/shaders/shader-coordSystem.vs", "../myResources/shaders/shader-coordSystem.fs");
//
//
//#pragma region vertexdata
//    float vertices[] = {
//        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//         0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//
//        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
//        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//
//        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//         0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//         0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
//         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//
//        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
//        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
//    };
//
//
//    unsigned int VBO, VAO, EBO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//    glGenBuffers(1, &EBO);
//
//    glBindVertexArray(VAO);
//
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//    //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//    // position attribute
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//    // texture
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//
//
//    // load and create a texture 
//    // -------------------------
//    unsigned int texture1, texture2;
//    glGenTextures(1, &texture1);
//
//    glBindTexture(GL_TEXTURE_2D, texture1); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
//    // set the texture wrapping parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    // set texture filtering parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    // load image, create texture and generate mipmaps
//    int width, height, nrChannels;
//
//    stbi_set_flip_vertically_on_load(true);
//    unsigned char* data = stbi_load("../myResources/textures/container.jpg", &width, &height, &nrChannels, 0);
//    if (data)
//    {
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//        glGenerateMipmap(GL_TEXTURE_2D);
//    }
//    else
//    {
//        std::cout << "Failed to load container texture" << std::endl;
//    }
//    stbi_image_free(data);
//
//    glGenTextures(1, &texture2);
//    glBindTexture(GL_TEXTURE_2D, texture2);
//    // set the texture wrapping parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    // set texture filtering parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    // load image, create texture and generate mipmaps
//    data = stbi_load("../myResources/textures/awesomeface.png", &width, &height, &nrChannels, 0);
//    if (data)
//    {
//        // note that the awesomeface.png has transparency and thus an alpha channel, so make sure to tell OpenGL the data type is of GL_RGBA
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//        glGenerateMipmap(GL_TEXTURE_2D);
//    }
//    else
//    {
//        std::cout << "Failed to load face texture" << std::endl;
//    }
//    stbi_image_free(data);
//
//    ourShader.use(); // don't forget to activate the shader before setting uniforms!  
//    glUniform1i(glGetUniformLocation(ourShader.ID, "texture1"), 0); // set it manually
//    ourShader.setInt("texture2", 1); // or with shader class
//
//
//#pragma endregion initializes vertex data, binds VAO and VBO, calls stbi_load image, TRANSFORMS
//    // render loop
//    // -----------
//
//
//#pragma region the render loop 
//    int frameNumber = 0;
//
//    float offset = 0.1f;
//
//    while (!glfwWindowShouldClose(window))
//    {
//        // input
//        // -----.
//        processInput(window);
//
//        glEnable(GL_DEPTH_TEST); 
//
//        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//        glActiveTexture(GL_TEXTURE0);
//        glBindTexture(GL_TEXTURE_2D, texture1);
//        glActiveTexture(GL_TEXTURE1);
//        glBindTexture(GL_TEXTURE_2D, texture2);
//
//
//        ourShader.use();
//
//
//
//
//        std::vector<glm::vec3> cubePositions =
//        {
//            glm::vec3(0.0f,  0.0f,  0.0f),
//            glm::vec3(2.0f,  5.0f, -20.0f),
//            glm::vec3(-1.5f, -2.2f, -2.5f),
//        };
//
//#pragma region CameraStuff
//        glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
//        glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
//        glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);
//
//        glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f); //y axis increases in the "up" direction 
//
//        glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));
//
//        glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);
//
//#pragma endregion initializes the camera vectors (vec3s)
//
//        glBindVertexArray(VAO);
//
//        for (int i = 0; i < cubePositions.size(); i++) //loop makes more than one cube (multiple draw calls) 
//        {
//            //model
//            glm::mat4 model = glm::mat4(1.0f);
//            
//            model = glm::translate(model, cubePositions[i]);
//            
//            //model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(1.0f, 0.0f, 0.0f));
//            unsigned int modelLoc = glGetUniformLocation(ourShader.ID, "model");
//            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//
//            //view 
//            glm::mat4 view = glm::mat4(1.0f);
//            view = glm::lookAt
//            (
//                glm::vec3(sin(glfwGetTime()), 0.0f, 3.0f), //camera's eyeball (varies x-coord w/time)
//                glm::vec3(0.0f, 0.0f, 0.0f), //camera's target
//                glm::vec3(0.0f, 1.0f, 0.0f)//camera's up direction 
//            ); 
//     
//            unsigned int viewLoc = glGetUniformLocation(ourShader.ID, "view");
//            glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//
//            //projection
//            glm::mat4 projection = glm::mat4(1.0f);
//            projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
//            unsigned int projectionLoc = glGetUniformLocation(ourShader.ID, "projection");
//            glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
//
//            //std::cout << transformLoc << "\t" << viewLoc << "\t" << projectionLoc << "\n";
//            glDrawArrays(GL_TRIANGLES, 0, 36);
//            //glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, 0);
//
//        }
//
//
//        ////end draw second
//
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//
//
//        //std::cout << "Frame number: " << frameNumber << "\tTime since init: " << timeValue << "\n";
//        frameNumber++;
//
//    }
//
//#pragma endregion calls useProgram and draw command
//
//    glDeleteVertexArrays(1, &VAO);
//    glDeleteBuffers(1, &VBO);
//
//
//    glfwTerminate();
//
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