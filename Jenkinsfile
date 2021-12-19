pipeline {
    agent any
    stages {
        stage('AllTests'){
            agent {
                dockerfile true
            }
            steps {
                sh 'pio test -e local'
            }
        }
    }
}