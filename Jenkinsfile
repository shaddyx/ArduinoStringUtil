pipeline {
    agent any
    stages {
        stage('AllTests'){
            agent {
                dockerfile true
            }
            steps {
                sh "cd ${env.WORKSPACE} && echo 'it works' && pio test -e local"
            }
        }
    }
}