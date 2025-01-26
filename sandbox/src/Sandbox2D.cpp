#include "Sandbox2D.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Platform/OpenGL/OpenGLShader.h"

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f) 
{
}

void Sandbox2D::OnAttach(){
	m_SquareVA = HyperR::VertexArray::Create() ;
	
	float squareVertices[5 * 4] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.5f,  0.5f, 0.0f,
			-0.5f,  0.5f, 0.0f
	};

	HyperR::Ref<HyperR::VertexBuffer> squareVB;

	squareVB.reset(HyperR::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));

	HyperR::BufferLayout layout = {
		{ HyperR::ShaderDataType::Float3, "a_Position" }

	};
	squareVB->SetLayout(layout);
	m_SquareVA->AddVertexBuffer(squareVB);

	uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };

	std::shared_ptr<HyperR::IndexBuffer> squareIB;

	squareIB.reset(HyperR::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));

	m_SquareVA->SetIndexBuffer(squareIB);

	m_FlatColorShader = HyperR::Shader::Create("assets/shaders/FlatColor.glsl");

}
void Sandbox2D::OnDetach() {

}
void Sandbox2D::OnUpdate(HyperR::Timestep ts) {
	m_CameraController.OnUpdate(ts);

	HyperR::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
	HyperR::RenderCommand::Clear();


	HyperR::Renderer::BeginScene(m_CameraController.GetCamera());

	glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

	std::dynamic_pointer_cast<HyperR::OpenGLShader>(m_FlatColorShader)->Bind();
	std::dynamic_pointer_cast<HyperR::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat4("u_Color", m_SquareColor);
	HyperR::Renderer::Submit(m_FlatColorShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

	HyperR::Renderer::EndScene();
}
void Sandbox2D::OnImGuiRender() {
	ImGui::Begin("Settings");
	ImGui::ColorEdit3("Flat Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}
void Sandbox2D::OnEvent(HyperR::Event& e) {
	m_CameraController.OnEvent(e);
}
