*This project has been created as part of the 42 curriculum by asyani

## Description

**Inception** is a System Administration project designed to broaden your knowledge of system operations and networking by utilizing Docker. The primary goal is to set up a small infrastructure composed of different services, each running in its own dedicated container. This project requires configuring an entire web setup from scratch using NGINX, WordPress (with PHP-FPM), and MariaDB.

### Project Design, Docker Usage, & Sources
This project relies heavily on Docker to containerize and isolate services. The main design choice dictates a strict "one service per container" rule. To achieve this, the infrastructure is orchestrated using Docker Compose. All images are built from a penultimate base OS (like Alpine or Debian) using custom `Dockerfile`s, as pre-configured or ready-made images (e.g., the official DockerHub `nginx` or `wordpress` images) are strictly forbidden by the subject. 

The sources included in this repository consist of:
*   **Dockerfiles:** Custom instructions to build each image from scratch.
*   **Configuration files:** Custom settings for the services (e.g., `nginx.conf`, `wp-config.php`, `my.cnf.d`).
*   **Initialization scripts:** Bash scripts (e.g., `entrypoint.sh`) used to bootstrap and configure the containers at runtime.
*   **Infrastructure management:** The `docker-compose.yml` file and a global `Makefile` to orchestrate the build, deployment, and teardown of the environment.

### Technical Comparisons

#### Virtual Machines vs Docker
*   **Virtual Machines:** Emulate an entire hardware system, running a full guest operating system on top of a hypervisor. This makes them heavier, slower to boot, and more resource-intensive.
*   **Docker:** Uses containerization to share the host's operating system kernel. Containers only pack the application and its direct dependencies, making them extremely lightweight, fast to start, and efficient in terms of CPU and RAM usage.

#### Secrets vs Environment Variables
*   **Secrets:** Secure, encrypted mechanisms (provided by tools like Docker Swarm) to store sensitive data like passwords and API keys. They are mounted directly in memory (tmpfs) and are not exposed in the image layers or container metadata.
*   **Environment Variables:** Plain text variables passed to the container at runtime. While highly convenient for configuration, they are inherently less secure because they are visible to anyone with access to the container host or via commands like `docker inspect`.

#### Docker Network vs Host Network
*   **Docker Network:** Creates an isolated virtual bridge for containers to communicate with each other securely using internal DNS resolution (via container names). It isolates traffic from the host machine and external networks.
*   **Host Network:** Removes network isolation entirely between the container and the Docker host. The container shares the host's networking namespace, meaning ports opened in the container are directly exposed on the host's IP address.

#### Docker Volumes vs Bind Mounts
*   **Docker Volumes:** Storage managed entirely by Docker within the host filesystem (e.g., `/var/lib/docker/volumes/`). They are the preferred mechanism for persisting data as they are independent of the host machine's directory structure, easily backed up, and can be shared among containers.
*   **Bind Mounts:** Map a specific, absolute path on the host system directly into a container. They rely heavily on the host machine's filesystem structure and permissions, making them less portable and more prone to host-side errors than volumes.

## Instructions

### Prerequisites
*   Docker and Docker Compose installed on your system.
*   `make` utility installed.
*   Your local `/etc/hosts` file must be modified to map your 42 login to localhost (e.g., `127.0.0.1 <login>.42.fr`).

### Compilation & Installation
1. Clone the repository to your local machine:
   `git clone <repository_url> && cd inception`
2. Set up the necessary environment variables in a `.env` file at the root of the `srcs` directory (e.g., database credentials, domain name, WordPress admin info).
3. Ensure the local directories required for data persistence (volumes) are created on your host machine as specified by the `Makefile` (usually `/home/<login>/data/wordpress` and `/home/<login>/data/mariadb`).

### Execution
To compile the images and start the infrastructure in the background, run the following command at the root of the repository:
`make`

Alternatively, you can run docker-compose manually from the source directory:
`cd srcs && docker-compose up --build -d`

Once running, you can access the WordPress site by navigating to `https://<login>.42.fr` in your web browser. Note that you will need to accept the self-signed SSL certificate.

To stop the containers and remove the networks and volumes, run:
`make down`

## Resources

*   **Docker Documentation:** [https://docs.docker.com/](https://docs.docker.com/)
*   **NGINX Official Documentation:** [https://nginx.org/en/docs/](https://nginx.org/en/docs/)
*   **MariaDB Knowledge Base:** [https://mariadb.com/kb/en/](https://mariadb.com/kb/en/)
*   **WordPress CLI (WP-CLI):** [https://make.wordpress.org/cli/handbook/](https://make.wordpress.org/cli/handbook/)
*   **docker:** [https://www.youtube.com/watch?v=PrusdhS2lmo&t=1709s](https://www.youtube.com/watch?v=PrusdhS2lmo&t=1709s)

### AI Usage
*   **Task:** Proofreading, structuring, and research assistance.
*   **Part of Project:** README file and Docker research.
