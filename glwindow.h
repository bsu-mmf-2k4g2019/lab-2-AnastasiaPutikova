#ifndef WIDGET_H
#define WIDGET_H

#include <QtOpenGL>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLWidget>

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = nullptr);
    ~GLWidget() override;

    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;

protected:
    void timerEvent(QTimerEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    // Shader programms
    QOpenGLShaderProgram m_prog_container;
    QOpenGLShaderProgram m_prog_triangle;
    QOpenGLShaderProgram m_prog_doublepyramid;

    // VAOs
    GLuint m_vao_container_id;
    GLuint m_vao_triangle_id;
    GLuint m_vao_doublepyramide_id;


    // Textures
    GLuint m_texture_bg_id;
    GLuint m_texture_smile_id;

    // Uniforms
    GLint  m_triangle_color_id;
    GLint  m_doublepyramid_color_id;


    QVector3D camera_pos;
    QVector3D camera_up;
    QVector3D camera_front;

    QTime frame_delta_time;
    QTime last_frame_time;
};

#endif // WIDGET_H
