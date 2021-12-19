pipeline {
    agent any
    stages {
        stage('AllTests'){
            agent {
                dockerfile true
            }
            steps {
                sh "cd ${env.WORKSPACE} && ./entrypoint.sh"
            }
        }
    }
}