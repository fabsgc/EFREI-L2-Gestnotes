<!DOCTYPE html>
<html style="opacity:0;">
	<head>
		<meta charset="utf-8" />
		<title>{$title} - GestNotes</title>
		<link rel="icon" type="image/png" href="/public/img/icon.png" />
		<link href="/public/css/default.css" rel="stylesheet" media="screen" type="text/css" /> 
		<link href="/public/file/font-awesome/css/font-awesome.min.css" rel="stylesheet" media="screen" type="text/css" />
		<script type="text/javascript" src="/public/js/jquery-1.11.2.min.js"></script>
		<script type="text/javascript" src="/public/js/default.js"></script>
	</head>
	<body id="body">
		<header class="default">
			<div id="header-left">
				<i class="fa fa-book"></i> GestNotes
			</div>
			<div id="header-right">
				<div class="right-account">
					<div id="logout" class="account-logout">
						<i class="fa fa-sign-out"></i>
					</div>
					<div class="account-profile">
						<div class="profile-username">
							{$session['firstname']} - {$session['name']}
						</div>
						<div class="profile-avatar">
							<img src="{$session['avatar']}"/>
						</div>
					</div>
				</div>
			</div>
			<div class="clear"/>
		</header>
		<div id="side-menu">
			<ul>
				<li <if condition="$request['controller'] == 'index'">class="active"</if>>
					<a href="/">
						<i class="fa fa-home"></i>
						<span class="title">Accueil</class>
					</a>
				</li>
				<li <if condition="$request['controller'] == 'user'">class="active"</if>>
					<a href="/user">
						<i class="fa fa-user"></i>
						<span class="title">Profil</class>
					</a>
				</li>
				<if condition="$session['role'] == $define['user-student']">
					<li <if condition="$request['controller'] == 'studentMark'">class="active"</if>>
						<a href="/student/mark">
							<i class="fa fa-university"></i>
							<span class="title">Notes</class>
						</a>
					</li>
					<li <if condition="$request['controller'] == 'studentCourse'">class="active"</if>>
						<a href="/student/course">
							<i class="fa fa-folder-open"></i>
							<span class="title">Cours</class>
						</a>
					</li>
				</if>
				<if condition="$session['role'] == $define['user-teacher']">
					<li <if condition="$request['controller'] == 'teacherMark'">class="active"</if>>
						<a href="/teacher/mark">
							<i class="fa fa-university"></i>
							<span class="title">Notes</class>
						</a>
					</li>
					<li <if condition="$request['controller'] == 'teacherCourse'">class="active"</if>>
						<a href="/teacher/course">
							<i class="fa fa-folder-open"></i>
							<span class="title">Cours</class>
						</a>
					</li>
					<li <if condition="$request['controller'] == 'teacherStudent'">class="active"</if>>
						<a href="/teacher/student">
							<i class="fa fa-users"></i>
							<span class="title">Élèves</class>
						</a>
					</li>
				</if>
				<if condition="$session['role'] == $define['user-admin']">
					<li <if condition="$request['controller'] == 'adminStudent'">class="active"</if>>
						<a href="/admin/student">
							<i class="fa fa-user-plus"></i>
							<span class="title">Élèves</class>
						</a>
					</li>
					<li <if condition="$request['controller'] == 'adminTeacher'">class="active"</if>>
						<a href="/admin/teacher">
							<i class="fa fa-binoculars"></i>
							<span class="title">Professeurs</class>
						</a>
					</li>
					<li <if condition="$request['controller'] == 'adminGroup'">class="active"</if>>
						<a href="/admin/group">
							<i class="fa fa-users"></i>
							<span class="title">Groupes</class>
						</a>
					</li>
					<li <if condition="$request['controller'] == 'adminCourse'">class="active"</if>>
						<a href="/admin/course">
							<i class="fa fa-folder-open"></i>
							<span class="title">Cours</class>
						</a>
					</li>
					<li <if condition="$request['controller'] == 'adminMark'">class="active"</if>>
						<a href="/admin/mark">
							<i class="fa fa-university"></i>
							<span class="title">Notes</class>
						</a>
					</li>
				</if>
			</ul>
		</div>
		<div id="main">
			<if condition="$request['controller'] != 'index'">
				<h2>{$title}</h2>
			</if>
			<div id="fil-ariane">
				<ul>
					<?php
						if(isset($filAriane))
						{
							$filAriane = explode('/', 'Accueil/'.$filAriane);
						}
						else
						{
							$filAriane = array('Accueil');
						}
					?>
					<foreach loop="$filAriane as $key => $value">
						<li>
							{$value}
						</li>
						<if condition="count($filAriane) > 1 && $key < count($filAriane)-1">
							<span class="fa fa-chevron-right">&#160;</span>
						</if>
					</foreach>
				</ul>
			</div>
			<include src="include/flashMessage"/>
			
