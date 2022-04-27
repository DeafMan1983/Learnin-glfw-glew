#include "DisplayManager.h"
#include "ProcessInputManager.h"
#include "Renderer.h"
#include "VertexArrayObject.h"
#include "BufferObject.h"
#include "Shader.h"
#include "ShaderProgram.h"
#include "Texture.h"
#include "Transformation.h"

#define GLSL(version, shader)  "#version " #version "\n" #shader

DisplayManager* dm;
const int WIDTH = 1280;
const int HEIGHT = 820;
const char* GLFW_GLEW_TITLE = "Learning with GLFW + GLEW - 05 Matrix (a) Transformation";
ProcessInputManager* pim;
Renderer* render;

float vertices[] =
{
	//position			texcoord	color			normal
	 0.5,  0.5, 0.0,	1.0, 1.0,	1.0, 0.0, 0.0,	0.0, 0.0, 1.0,
	 0.5, -0.5, 0.0,	1.0, 0.0,	0.0, 0.0, 1.0,	0.0, 0.0, 1.0,
	-0.5, -0.5, 0.0,	0.0, 0.0,	0.0, 1.0, 0.0,	0.0, 0.0, 1.0,
	-0.5,  0.5, 0.0,	0.0, 1.0,	1.0, 1.0, 0.0,	0.0, 0.0, 1.0
};
int vertex_loc, texture_loc, color_loc, normal_loc;

VertexArrayObject* vao;
BufferObject* vbo;

unsigned int indices[] =
{
	0, 1, 3,	// first triangle
	1, 2, 3		// second triangle;
};

BufferObject* ebo;

const char* vertex_source = GLSL(450 core,
	layout(location = 0) in vec3 position0;
	layout(location = 1) in vec2 texcoords0;
	layout(location = 2) in vec3 color0;
	layout(location = 3) in vec3 normal0;

	out vec2 texCoords;
	out vec3 color;
	out vec3 normal;

	uniform mat4 transform;

	void main()
	{
		gl_Position = transform * vec4(position0.x, position0.y, position0.z, 1.0);
		texCoords = texcoords0;
		color = color0;
		normal = normal0;
	}
);
Shader* vertex_shader;

const char* fragment_source = GLSL(450 core,
	in vec2 texCoords;
	in vec3 color;
	out vec4 FragColor;

	uniform sampler2D texture1;
	uniform float time;

	void main()
	{
		FragColor = texture(texture1, vec2(texCoords.x + time, texCoords.y)) * vec4(color, 1.0f);
	}
);
Shader* fragment_shader;
ShaderProgram* shader_program;
Texture* checkedTexure;

Transformation* transform;

int main()
{
	dm = DisplayManager::Create(GLFW_GLEW_TITLE, WIDTH, HEIGHT);
	pim = new ProcessInputManager(dm->GetWindow());
	pim->FrameBufferSize(ProcessInputManager::FrameBufferSizeCallBack);

	vertex_shader = Shader::Create(GL_VERTEX_SHADER, vertex_source);
	fragment_shader = Shader::Create(GL_FRAGMENT_SHADER, fragment_source);
	shader_program = ShaderProgram::Attach(vertex_shader, fragment_shader);

	vao = VertexArrayObject::Gen();
	vbo = BufferObject::Gen();
	ebo = BufferObject::Gen();

	checkedTexure = Texture::Gen();

	vao->Bind();
	vbo->Bind(GL_ARRAY_BUFFER);
	ebo->Bind(GL_ELEMENT_ARRAY_BUFFER);

	vbo->Data(sizeof(vertices), vertices, GL_STATIC_DRAW);

	int stride = 11 * sizeof(float);

	vertex_loc = shader_program->GetAttributeLocation("position0");
	vbo->Pointer(vertex_loc, 3, stride, (void*)0);
	vbo->Enable(vertex_loc);

	texture_loc = shader_program->GetAttributeLocation("texcoords0");
	vbo->Pointer(texture_loc, 2, stride, (void*)(3 * sizeof(float)));
	vbo->Enable(texture_loc);

	color_loc = shader_program->GetAttributeLocation("color0");
	vbo->Pointer(color_loc, 3, stride, (void*)(5 * sizeof(float)));
	vbo->Enable(color_loc);

	normal_loc = shader_program->GetAttributeLocation("normal0");
	vbo->Pointer(normal_loc, 3, stride, (void*)(8 * sizeof(float)));
	vbo->Enable(normal_loc);

	ebo->Data(sizeof(indices), indices, GL_STATIC_DRAW);

	checkedTexure->Bind(GL_TEXTURE_2D);
	checkedTexure->Parameter(GL_TEXTURE_WRAP_S, GL_REPEAT);
	checkedTexure->Parameter(GL_TEXTURE_WRAP_T, GL_REPEAT);
	checkedTexure->Parameter(GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
	checkedTexure->Parameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	checkedTexure->Load("texture.png", GL_RGB);

	shader_program->Detach();

	while (dm->IsRunning())
	{
		// ProcessInputManager
		pim->Close();
		pim->SwitchFillAndLine();

		// Renderer
		render = Renderer::Prepare(GL_COLOR_BUFFER_BIT, 1.0f, 1.0f * 0.35f, 0.0f);

		shader_program->Use();

		checkedTexure->Activate(GL_TEXTURE0);
		checkedTexure->Bind(GL_TEXTURE_2D);

		shader_program->SetInt("texture1", 0);

		float time = (float)glfwGetTime();
		time += checkedTexure->GetWidth() + 0.25f;
		shader_program->SetFloat("time", time);

		transform = Transformation::Identify();
		transform->Rotate((float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
		shader_program->SetMat4("transform", glm::value_ptr(transform->GetMat4()));

		vao->Bind();
		render->Draw(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		dm->Poll();
	}

	// Disable locations
	vbo->Disable(color_loc);
	vbo->Disable(texture_loc);
	vbo->Disable(vertex_loc);

	// Clean up
	checkedTexure->Delete();
	shader_program->Delete();
	fragment_shader->Delete();
	vertex_shader->Delete();
	vbo->Delete();
	vao->Delete();
	dm->Destroy();
}